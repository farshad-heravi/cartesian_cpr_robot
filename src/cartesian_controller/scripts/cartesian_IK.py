import rospy
from sensor_msgs.msg import JointState


class CartesianRobot:
    def __init__(self, 
            motor_names = ['motor1', 'motor2'],
            motor_ratios = [5, 3],               # m/rad
            joint_topics = ['joint1', 'joint2']
            ) -> None:
        self.__motor_name = motor_names
        self.__x_offset = 0  # FIXME
        self.__y_offset = 0  # FIXME
    
        self.__motor1 = self.Motor(motor_ratios[0])
        self.__motor2 = self.Motor(motor_ratios[1])

        self.__pub1 = rospy.Publisher(joint_topics[0], )

    
    def IK(self, ee_pos):
        delta_x = ee_pos[0] - self.__x_offset
        delta_y = ee_pos[1] - self.__y_offset

        delta_theta_1 = delta_x / self.__motor1.ratio       # obtain required rotation of motor1 to fulfill the delta_x movement
        delta_theta_2 = delta_y / self.__motor2.ratio       # obtain required rotation of motor2 to fulfill the delta_y movement

        return delta_theta_1, delta_theta_2

    def goto(self, ee_pos):
        theta1, theta2 = self.IK(ee_pos)
        
    def publish(self, thetas):


    class Motor():
        def __init__(self,
            linear2rotation_ratio) -> None:
            self.__linear2rotation_ratio = linear2rotation_ratio

        @property
        def ratio(self):
            return self.__linear2rotation_ratio
        @ratio.setter
        def ratio(self, value):
            assert value != 0, 'Motor Ratio Cannot be ZERO!'
            self.__linear2rotation_ratio = value


robot = CartesianRobot()
robot.goto([10, 5])