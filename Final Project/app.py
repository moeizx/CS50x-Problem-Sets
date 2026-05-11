from flask import Flask, render_template, request, redirect
import sqlite3
from collections import defaultdict

app = Flask(__name__)


def get_db_connection():
    conn = sqlite3.connect("database.db")
    conn.row_factory = sqlite3.Row
    return conn


# HOME (DASHBOARD)
@app.route("/")
def dashboard():
    conn = get_db_connection()
    trades = conn.execute("SELECT * FROM trades").fetchall()
    conn.close()

    total_trades = len(trades)
    wins = 0
    losses = 0
    valid_trades = 0

    strategy_data = defaultdict(lambda: {"wins": 0, "total": 0})

    for trade in trades:
        try:
            entry = float(trade["entry_price"])
            exit_price = float(trade["exit_price"])
            trade_type = trade["trade_type"]
            strategy = trade["strategy"] or "Unknown"

            # ✅ correct PnL logic
            if trade_type == "Buy":
                pnl = exit_price - entry
            else:  # Sell
                pnl = entry - exit_price

            valid_trades += 1
            strategy_data[strategy]["total"] += 1

            if pnl > 0:
                wins += 1
                strategy_data[strategy]["wins"] += 1
            else:
                losses += 1

        except Exception as e:
            print("Error processing trade:", e)

    win_rate = (wins / valid_trades * 100) if valid_trades > 0 else 0

    strategy_stats = []

    for strategy, data in strategy_data.items():
        wr = (data["wins"] / data["total"]) * 100 if data["total"] > 0 else 0

        strategy_stats.append({
            "strategy": strategy,
            "total": data["total"],
            "win_rate": round(wr, 2)
        })

    return render_template(
        "index.html",
        total_trades=total_trades,
        wins=wins,
        losses=losses,
        win_rate=round(win_rate, 2),
        strategy_stats=strategy_stats
    )



# HISTORY
@app.route("/history")
def history():
    conn = get_db_connection()
    trades = conn.execute("SELECT * FROM trades").fetchall()
    conn.close()

    return render_template("history.html", trades=trades)


# ADD TRADE
@app.route("/add", methods=["GET", "POST"])
def add():
    if request.method == "POST":
        pair = request.form["pair"]
        entry = request.form["entry_price"]
        exit_price = request.form["exit_price"]
        lot = request.form["lot_size"]
        trade_type = request.form["trade_type"]
        strategy = request.form["strategy"]
        emotion = request.form["emotion"]
        notes = request.form["notes"]

        conn = get_db_connection()
        conn.execute(
            """
            INSERT INTO trades 
            (pair, entry_price, exit_price, lot_size, trade_type, strategy, emotion, notes) 
            VALUES (?, ?, ?, ?, ?, ?, ?, ?)
            """,
            (pair, entry, exit_price, lot, trade_type, strategy, emotion, notes)
        )
        conn.commit()
        conn.close()

        return redirect("/")

    return render_template("add.html")



# DELETE TRADE
@app.route("/delete/<int:id>")
def delete(id):
    conn = get_db_connection()
    conn.execute("DELETE FROM trades WHERE id = ?", (id,))
    conn.commit()
    conn.close()

    return redirect("/history")



# EDIT TRADE
@app.route("/edit/<int:id>", methods=["GET", "POST"])
def edit(id):
    conn = get_db_connection()

    trade = conn.execute(
        "SELECT * FROM trades WHERE id = ?",
        (id,)
    ).fetchone()

    if request.method == "POST":
        pair = request.form["pair"]
        entry = request.form["entry_price"]
        exit_price = request.form["exit_price"]
        lot = request.form["lot_size"]
        trade_type = request.form["trade_type"]
        strategy = request.form["strategy"]
        emotion = request.form["emotion"]
        notes = request.form["notes"]

        conn.execute("""
            UPDATE trades
            SET pair = ?, entry_price = ?, exit_price = ?, lot_size = ?, 
                trade_type = ?, strategy = ?, emotion = ?, notes = ?
            WHERE id = ?
        """, (pair, entry, exit_price, lot, trade_type, strategy, emotion, notes, id))

        conn.commit()
        conn.close()

        return redirect("/history")

    conn.close()

    return render_template("edit_trade.html", trade=trade)



if __name__ == "__main__":
    app.run(debug=True)