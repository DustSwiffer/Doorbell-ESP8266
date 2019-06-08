# imports
from flask import Flask, jsonify, request
from flask_restful import Api, Resource, reqparse
import requests
import os
import pygame
from time import sleep             # lets us have a delay 
app = Flask(__name__)
api = Api(app)

doorbeltrigger = 0

class Ring(Resource):
    def get(self):
        doorbeltrigger = 1
        if(doorbeltrigger == 1):
            pygame.mixer.init()
            pygame.mixer.music.load('doorbell.mp3')
            pygame.mixer.music.play(999)
            sleep(4)
            pygame.mixer.music.stop()
            doorbeltrigger = 0
            return 200




api.add_resource(Ring, "/ring")
app.run(host='0.0.0.0', port='5001', debug=True)