const finder = document.querySelector('.search-button'); // Add dot for class selector

const getLocation = () => {
    navigator.geolocation.getCurrentPosition(
        (position) => {
            console.log(position);
        },
        (error) => {
            console.error('Error getting location:', error);
            alert('Unable to retrieve your location');
        }
    );
};

finder.addEventListener('click', getLocation); // Remove arrow function and parentheses