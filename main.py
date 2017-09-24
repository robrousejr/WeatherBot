import requests
import exportData
import serial
from time import sleep
ser = serial.Serial('COM6', 9600) # Establish the connection on a specific port
#arduino = exportData.Arduino()


api_address = "http://api.openweathermap.org/data/2.5/weather?appid=a82b0112a97d4ff8f769c682931dbc5c&q="
city = input("City Name: ")
url = (api_address + city)
json_Data = requests.get(url).json()

# Declaring the JSON variables in Python
kelvinTemp = (json_Data['main']['temp']) # Kelvin temp
description = (json_Data['weather'][0]['main']) # eg Clear Sky, Sunny, etc.
tempMaxKelvin = (json_Data['main']['temp_max']) # maximum temp in Kelvin
tempMaxFahren =  9/5 * (tempMaxKelvin - 273) + 32 # Max Temp to Fahrenheit
tempMaxFahren = str(round(tempMaxFahren, 2)) # 2 decimal places
tempMinKelvin = (json_Data['main']['temp_min']) # Minimum Temp in Kelvin
tempMinFahren = 9/5 * (tempMinKelvin - 273) + 32 # Minimum Temp to Fahrenheit
tempMinFahren = str(round(tempMinFahren, 2)) # Only 2 decimal places in Fahrenheit min temp
windSpeed = (json_Data['wind']['speed']) # windSpeed, add "MPH" when print
humidity = (json_Data['main']['humidity']) # humidity, add "%" when print
name = (json_Data['name'])

fahrenTemp = 9/5 * (kelvinTemp - 273) + 32 # Fahrenheit temp conversion
fahrenTemp = str(round(fahrenTemp, 2)) # Fahrenheit only 2 decimal places

# Bunch of print functions
'''
print ("\n\nIn", name, "It is:")
print (fahrenTemp, "degrees Fahrenheit")
print (description)
print (tempMinFahren, "degrees MAX today")
print (tempMinFahren, "degrees MIN today")
print (windSpeed, "MPH winds today")
print (humidity, "% humidity")
'''
if description == "Mist":
	string = '&'
	ser.write(bytes(str(string), encoding='ascii')) #Sends signal that it's misty

if description == "Clear" and city is "Akron":
	string = '$'
	ser.write(bytes(str(string), encoding='ascii')) #Sends signal that it's cleary

if description == "Clear" and city is not "Akron":
	string = '@'
	ser.write(bytes(str(string), encoding='ascii'))  # Sends signal that it's cleary but not as awesomey

if description == "Rain" or description == "Thunderstorm":
	string = '^'
	ser.write(bytes(str(string), encoding='ascii')) #Sends signal that it's rainy

if description == "Clouds":
	string = '>'
	ser.write(bytes(str(string), encoding='ascii'))  # Sends signal that it's cloudy

if description == "Snow":
	string = '_'
	ser.write(bytes(str(string), encoding='ascii')) #Sends signal that it's snowy

string = '?'
ser.write(bytes(str(string), encoding='ascii'))    #Sends signal to clear the LCD

string = (str(city) + "'s Weather")
for counter in string:
	ser.write(bytes(str(counter), encoding='ascii'))  # Convert the decimal number to ASCII then send it to the Arduino
	print(ser.readline())  # Read the newest output from the Arduino
	sleep(.01)
sleep(3)

string = '?'
ser.write(bytes(str(string), encoding='ascii'))    #Sends signal to clear the LCD


string = str(description)
for counter in string:
	ser.write(bytes(str(counter), encoding='ascii'))  # Convert the decimal number to ASCII then send it to the Arduino
	print(ser.readline())  # Read the newest output from the Arduino
	sleep(.01)
sleep(3)

string = '?'
ser.write(bytes(str(string), encoding='ascii'))    #Sends signal to clear the LCD

string = "Temp: " + str(fahrenTemp) + " F"
for counter in string:
    ser.write(bytes(str(counter), encoding='ascii')) # Convert the decimal number to ASCII then send it to the Arduino
    print(ser.readline()) # Read the newest output from the Arduino
    sleep(.01)
sleep(3)

string = '?'
ser.write(bytes(str(string), encoding='ascii'))    #Sends signal to clear the LCD

string = "Humidity: " + str(humidity) + " %"
for counter in string:
    ser.write(bytes(str(counter), encoding='ascii')) # Convert the decimal number to ASCII then send it to the Arduino
    print(ser.readline()) # Read the newest output from the Arduino
    sleep(.01)
sleep(3)

string = '?'
ser.write(bytes(str(string), encoding='ascii'))    #Sends signal to clear the LCD

string = "Wind Speed: " + str(windSpeed) + " MPH"
for counter in string:
    ser.write(bytes(str(counter), encoding='ascii')) # Convert the decimal number to ASCII then send it to the Arduino
    print(ser.readline()) # Read the newest output from the Arduino
    sleep(.01)
sleep(3)


