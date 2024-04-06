// Function to display a greeting based on the current time
function displayGreetingBasedOnTime() {
    const hour = new Date().getHours(); // Gets the current hour
    let greeting;
    // Determine the appropriate greeting based on the current hour
    if (hour < 12) {
        greeting = "Good morning!";
    } else if (hour < 18) {
        greeting = "Good afternoon!";
    } else {
        greeting = "Good evening!";
    }
    // Set the text content of the element with ID 'greeting' to the determined greeting
    document.getElementById("greeting").textContent = greeting;
}

// Event listener to call the displayGreetingBasedOnTime function after the DOM has fully loaded
document.addEventListener("DOMContentLoaded", displayGreetingBasedOnTime);

// Event listener for the notification button
document.getElementById('notifyButton').addEventListener('click', function() {
    // Display a browser alert with a notification message
    alert('This is a notification!');
});

// Counter variable to track the number of times a button is clicked
let count = 0;

// Event listener for the click button
document.getElementById('clickButton').addEventListener('click', function() {
    count++; // Increment the counter
    // Update the text content of the element with ID 'clickCount' to show the updated count
    document.getElementById('clickCount').textContent = count;
});

// Function to toggle the visibility of color options based on the selected theme
function toggleColorOptions(theme) {
    // Get the div that contains the color options for the selected theme
    const optionsDiv = document.getElementById(`${theme}-options`);
    // Toggle the display style between none and block to show or hide the div
    if (optionsDiv.style.display === "none") {
        optionsDiv.style.display = "block";
    } else {
        optionsDiv.style.display = "none";
    }
}

// Function to change the color scheme of the page
function changeColorScheme(scheme) {
    // Set the class name of the body to the selected color scheme which applies the corresponding styles
    document.body.className = scheme;
}

// Event listener for the form submission
document.getElementById("myForm").addEventListener("submit", function(event) {
    event.preventDefault(); // Prevent the default form submission behavior

    let isValid = true; // Flag to track the validity of the form
    let feedbackText = ''; // Text to provide feedback to the user

    // Get the values from the form inputs
    let name = document.getElementById("name").value;
    let email = document.getElementById("email").value;
    let password = document.getElementById("password").value;
    let message = document.getElementById("message").value;

    // Feedback logic (this example assumes validity but should include validation logic)
    const feedbackElement = document.getElementById("formFeedback");
    if (isValid) {
        feedbackText = "Form submitted successfully!";
        feedbackElement.style.color = 'green'; // Set feedback text color to green for success
    } else {
        feedbackText = "Please fill out all fields!";
        feedbackElement.style.color = 'red'; // Set feedback text color to red for error
    }
    feedbackElement.textContent = feedbackText; // Update the feedback element with the feedback text
});
