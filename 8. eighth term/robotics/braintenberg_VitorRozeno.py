import numpy as np


def sysCall_init():
    sim = require("sim")

    global motorL, motorR, sensors, braintenL, braintenR, v0, detect, noDetec, maxDetec

    robo = sim.getObjectHandle("Pioneer_p3dx")

    # obstaculos
    obstacles = sim.createCollection(0)
    sim.addItemToCollection(obstacles, sim.handle_all, -1, 0)
    sim.addItemToCollection(obstacles, sim.handle_tree, robo, 1)

    # configuracao dos sensores
    sensors = []
    for i in range(16):
        sensor_handle = sim.getObjectHandle(f"Pioneer_p3dx_ultrasonicSensor{i+1}")
        sim.setObjectInt32Param(
            sensor_handle, sim.proxintparam_entity_to_detect, obstacles
        )
        sensors.append(sensor_handle)

    # Configuracao dos motores
    motorL = sim.getObjectHandle("Pioneer_p3dx_leftMotor")
    motorR = sim.getObjectHandle("Pioneer_p3dx_rightMotor")

    # algoritmo de braintenberg
    noDetec = 0.5
    maxDetec = 0.2
    detect = np.zeros(16)  
    braintenL = [
        -0.2,
        -0.4,
        -0.6,
        -0.8,
        -1,
        -1.2,
        -1.4,
        -1.6,
        0.0,
        0.0,
        0.0,
        0.0,
        0.0,
        0.0,
        0.0,
        0.0,
    ]
    braintenR = [
        -1.6,
        -1.4,
        -1.2,
        -1,
        -0.8,
        -0.6,
        -0.4,
        -0.2,
        0.0,
        0.0,
        0.0,
        0.0,
        0.0,
        0.0,
        0.0,
        0.0,
    ]
    v0 = 2


def sysCall_actuation():
    global detect

    # leitura dos sensores
    for i in range(16):
        res, dist, _, _, _ = sim.readProximitySensor(sensors[i])
        if res and dist < noDetec:
            if dist < maxDetec:
                dist = maxDetec
            detect[i] = 1 - ((dist - maxDetec) / (noDetec - maxDetec))
        else:
            detect[i] = 0

    # velocidades
    veloL = v0
    veloR = v0

    # aplicacao do algoritmo
    for i in range(16):
        veloL += braintenL[i] * detect[i]
        veloR += braintenR[i] * detect[i]

    # definicao da velocidade
    sim.setJointTargetVelocity(motorL, veloL)
    sim.setJointTargetVelocity(motorR, veloR)


def sysCall_cleanup():
    pass


if __name__ == "__main__":
    sysCall_init()
    while True:
        sysCall_actuation()
