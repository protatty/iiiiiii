<html>
<head>

</head>
<body>
<p id="location"></p>
<p id="locat"></p> 
<h1>hi</h1>
<script type="text/javascript" charset="utf-8">
  document.getElementById("locat").innerHTML = "xxxxxxxxxxxxxx";
  function getLocation() {
    // Если геолокация поддерживается браузером
    if (geoPosition.init()){ 
geoPosition.getCurrentPosition(showPosition);
	}else{	document.getElementById("location").innerHTML = "Геолокация не поддерживается.";
	}
  }

  function showPosition(position) {
    var lat = position.latitude;
    var lon = position.longitude;
    document.getElementById("location").innerHTML = "Широта: " + lat + "<br>Долгота: " + lon;
  }
getLocation();

</script>
</body>
</html>
