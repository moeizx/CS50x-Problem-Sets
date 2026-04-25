function sayHello() {
    document.getElementById("message").innerText =
        "Hello! JavaScript is working";
}

// extra interactivity: recurring effect
setInterval(function () {
    console.log("Page is active...");
}, 5000);
