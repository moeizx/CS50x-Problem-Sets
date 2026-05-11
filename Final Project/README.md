# Trading Journal Web App  
#### Video Demo: https://youtu.be/TzCit336QpU

#### Description:

This project is a web-based trading journal application built using Flask and SQLite. The goal of this application is to provide traders with a simple yet effective way to log their trades, analyze performance, and evaluate the effectiveness of different trading strategies.

The application follows a clean, minimal SaaS-style design and focuses on usability and clarity. Instead of overwhelming the user with complex analytics, it provides the most essential insights needed to improve trading decisions.

---

## Overview

The application consists of three main pages:

1. Home (Dashboard)  
2. Add Trade  
3. Trade History  

Each page serves a specific purpose in the workflow of tracking and analyzing trades.

---

## Home Page (Dashboard)

The home page acts as the central dashboard of the application. It provides a quick overview of trading performance through key metrics:

- Total number of trades  
- Number of winning trades  
- Number of losing trades  
- Overall win rate  

These metrics are calculated dynamically from the stored trade data in the database. The logic correctly handles both Buy and Sell trades to ensure accurate results.

Below the summary cards, the dashboard also displays strategy-based performance. Each strategy is listed along with:

- Total trades executed using that strategy  
- Win rate for that strategy  

This allows users to evaluate which strategies are performing well and which may need improvement.

---

## Add Trade Page

The Add Trade page allows users to record new trades. It contains a structured form with the following inputs:

- Trading pair  
- Entry price  
- Exit price  
- Lot size  
- Trade type (Buy or Sell)  
- Strategy  
- Emotion  
- Notes  

Once the form is submitted, the trade is saved into the SQLite database and the user is redirected back to the dashboard.

The form design emphasizes simplicity and speed, making it easy to log trades without unnecessary friction. Autofill is disabled to ensure users enter intentional and accurate data.

---

## Trade History Page

The Trade History page displays all recorded trades in a tabular format. Each trade includes:

- Pair  
- Entry and exit prices  
- Lot size  
- Trade type  
- Strategy  
- Emotion  
- Notes  

The notes field is designed to handle long text without breaking the layout by using a scrollable container.

Each trade also includes two actions:

- Edit: Allows modification of existing trade details  
- Delete: Removes the trade from the database  

The IDs shown in the table are UI-based (using loop indexing) rather than database IDs. This ensures a clean and continuous numbering system even after deletions.

---

## File Structure and Responsibilities

### app.py

This is the core backend of the application built with Flask. It handles routing, database interactions, and business logic.

Key responsibilities include:

- Connecting to the SQLite database  
- Handling CRUD operations (Create, Read, Update, Delete)  
- Calculating performance metrics such as win rate  
- Processing strategy-based statistics  

A key design decision here was implementing correct PnL calculation for both Buy and Sell trades. This ensures accurate performance tracking.

---

### templates/base.html

This file defines the main layout of the application. It includes:

- Navigation bar  
- Global styling  
- Page container  

All other pages extend this base template, ensuring consistency in design and layout across the application.

---

### templates/index.html

This file represents the dashboard. It displays:

- Performance summary cards  
- Strategy performance table  

The data is dynamically passed from Flask and rendered using Jinja2 templating.

---

### templates/add.html

This file contains the form used to add new trades. It is designed with careful spacing and alignment to provide a clean user experience.

The form is fully styled using inline CSS to maintain a consistent visual theme with the rest of the application.

---

### templates/history.html

This file displays the trade history in a structured table format. It also includes:

- Scrollable notes column  
- Edit and delete action links  

The layout ensures that even large amounts of data remain readable and organized.

---

### templates/edit_trade.html

This page allows users to update an existing trade. It pre-fills the form with current values and updates the database upon submission.

---

## Design Decisions

Several design choices were made during development:

### 1. Server-Side Rendering Instead of JavaScript

The application uses Flask with Jinja2 templates instead of a frontend JavaScript framework. This was done to keep the architecture simple and focused on backend logic.

While JavaScript could provide features like real-time updates, it was not necessary for the core functionality of this project.

---

### 2. SQLite as Database

SQLite was chosen because it is lightweight, requires no setup, and is perfect for small to medium-scale applications.

---

### 3. Minimal UI Design

The interface follows a clean and minimal dark theme. The goal was to reduce distractions and keep the focus on data.

Unnecessary colors and visual clutter were avoided to maintain a professional SaaS-like appearance.

---

### 4. Error Handling Strategy

Instead of silently ignoring errors, exceptions are logged during trade processing. This helps with debugging and ensures that invalid data does not corrupt calculations.

---

## Conclusion

This trading journal application demonstrates a complete full-stack workflow using Flask, SQLite, and Jinja2. It covers all essential CRUD operations and includes meaningful data analysis features.

The project focuses on practical usability and provides a strong foundation that can be extended further with features like charts, filtering, or real-time updates.

Overall, it serves as a solid example of building a functional and clean web application from scratch.

---

## Setup Instructions

1. Install dependencies:
   pip install -r requirements.txt

2. Initialize the database:
   sqlite3 database.db < schema.sql

3. Run the app:
   python app.py