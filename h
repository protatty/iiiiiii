<!DOCTYPE html>
<html lang="ru">
<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>GPS Местоположение на Яндекс.Картах</title>
    <link rel="stylesheet" href="https://api-maps.yandex.ru/2.1/style.css" />
    <script src="https://api-maps.yandex.ru/2.1/?lang=ru_RU" type="text/javascript"></script>
    <style>
        #map {
            width: 100%;
            height: 400px;
        }
    </style>
<script src="js/geoPosition.js" type="text/javascript" charset="utf-8"></script>
</head>
<body>
    <div id="map"></div>

    <script type="text/javascript">
	if(geoPosition.init()){  // Geolocation Initialisation
			geoPosition.getCurrentPosition(success_callback,error_callback,{enableHighAccuracy:true});
	}else{
			// You cannot use Geolocation in this device
	}
	geoPositionSimulator.init(); 

	// p : geolocation object
	function success_callback(p){
		// p.latitude : latitude value
		// p.longitude : longitude value
	}

	function error_callback(p){
		// p.message : error message
	}
</script>
        
        
        
        
        <script>
        // Функция для инициализации карты
        function initMap(latitude, longitude) {
            const myMap = new ymaps.Map("map", {
                center: [latitude, longitude],
                zoom: 15
            });

            const placemark = new ymaps.Placemark([latitude, longitude], {
                balloonContent: 'Вы находитесь здесь!'
            });

            myMap.geoObjects.add(placemark);
        }

        // Функция для получения координат GPS
        function getLocation() {
            if (navigator.geolocation) {
                navigator.geolocation.getCurrentPosition(position => {
                    const latitude = position.coords.latitude;
                    const longitude = position.coords.longitude;
                    ymaps.ready(() => initMap(latitude, longitude));
                }, () => {
                    alert("Ошибка при определении местоположения.");
                });
            } else {
                alert("Ваш браузер не поддерживает геолокацию.");
            }
        }

        document.addEventListener('DOMContentLoaded', getLocation);
    </script>
</body>
</html>





