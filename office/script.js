const button = document.querySelector('.search-button');
async function getWeather(cityName){
    let url = `https://api.weatherapi.com/v1/current.json?key=7e531fa0e0d24676a5c70609250701&q=${cityName}&aqi=yes`
    const response = await fetch(url);
    return await response.json();
}

const printWeather = async () => {
    try{
        const searched = document.querySelector('.city').value;
        if (!searched) {
            alert('Please enter a city name');
            return;
        }
        const data = await getWeather(searched);
        const result = document.querySelector('.result');
        result.innerHTML = `<div>${data.location.name}</div> <div>${data.current.temp_c}°C</div> <div>${data.current.condition.text}</div>`;
    } catch (error) {
        console.error('Error fetching weather:', error);
        alert('Error fetching weather data. Please try again.');
    }
};

const input = document.querySelector('.city');
button.addEventListener('click',printWeather);
input.addEventListener('keypress',(event) => {
    if (event.key === 'Enter') {
        printWeather();
    }
});

