# generated from rosidl_generator_py/resource/_idl.py.em
# with input from myinterfaces:srv/Humancoordinates.idl
# generated code does not contain a copyright notice


# Import statements for member types

import builtins  # noqa: E402, I100

import rosidl_parser.definition  # noqa: E402, I100


class Metaclass_Humancoordinates_Request(type):
    """Metaclass of message 'Humancoordinates_Request'."""

    _CREATE_ROS_MESSAGE = None
    _CONVERT_FROM_PY = None
    _CONVERT_TO_PY = None
    _DESTROY_ROS_MESSAGE = None
    _TYPE_SUPPORT = None

    __constants = {
    }

    @classmethod
    def __import_type_support__(cls):
        try:
            from rosidl_generator_py import import_type_support
            module = import_type_support('myinterfaces')
        except ImportError:
            import logging
            import traceback
            logger = logging.getLogger(
                'myinterfaces.srv.Humancoordinates_Request')
            logger.debug(
                'Failed to import needed modules for type support:\n' +
                traceback.format_exc())
        else:
            cls._CREATE_ROS_MESSAGE = module.create_ros_message_msg__srv__humancoordinates__request
            cls._CONVERT_FROM_PY = module.convert_from_py_msg__srv__humancoordinates__request
            cls._CONVERT_TO_PY = module.convert_to_py_msg__srv__humancoordinates__request
            cls._TYPE_SUPPORT = module.type_support_msg__srv__humancoordinates__request
            cls._DESTROY_ROS_MESSAGE = module.destroy_ros_message_msg__srv__humancoordinates__request

            from sensor_msgs.msg import CameraInfo
            if CameraInfo.__class__._TYPE_SUPPORT is None:
                CameraInfo.__class__.__import_type_support__()

            from sensor_msgs.msg import Image
            if Image.__class__._TYPE_SUPPORT is None:
                Image.__class__.__import_type_support__()

    @classmethod
    def __prepare__(cls, name, bases, **kwargs):
        # list constant names here so that they appear in the help text of
        # the message class under "Data and other attributes defined here:"
        # as well as populate each message instance
        return {
        }


class Humancoordinates_Request(metaclass=Metaclass_Humancoordinates_Request):
    """Message class 'Humancoordinates_Request'."""

    __slots__ = [
        '_camera_info',
        '_image',
        '_depth_image',
    ]

    _fields_and_field_types = {
        'camera_info': 'sensor_msgs/CameraInfo',
        'image': 'sensor_msgs/Image',
        'depth_image': 'sensor_msgs/Image',
    }

    SLOT_TYPES = (
        rosidl_parser.definition.NamespacedType(['sensor_msgs', 'msg'], 'CameraInfo'),  # noqa: E501
        rosidl_parser.definition.NamespacedType(['sensor_msgs', 'msg'], 'Image'),  # noqa: E501
        rosidl_parser.definition.NamespacedType(['sensor_msgs', 'msg'], 'Image'),  # noqa: E501
    )

    def __init__(self, **kwargs):
        assert all('_' + key in self.__slots__ for key in kwargs.keys()), \
            'Invalid arguments passed to constructor: %s' % \
            ', '.join(sorted(k for k in kwargs.keys() if '_' + k not in self.__slots__))
        from sensor_msgs.msg import CameraInfo
        self.camera_info = kwargs.get('camera_info', CameraInfo())
        from sensor_msgs.msg import Image
        self.image = kwargs.get('image', Image())
        from sensor_msgs.msg import Image
        self.depth_image = kwargs.get('depth_image', Image())

    def __repr__(self):
        typename = self.__class__.__module__.split('.')
        typename.pop()
        typename.append(self.__class__.__name__)
        args = []
        for s, t in zip(self.__slots__, self.SLOT_TYPES):
            field = getattr(self, s)
            fieldstr = repr(field)
            # We use Python array type for fields that can be directly stored
            # in them, and "normal" sequences for everything else.  If it is
            # a type that we store in an array, strip off the 'array' portion.
            if (
                isinstance(t, rosidl_parser.definition.AbstractSequence) and
                isinstance(t.value_type, rosidl_parser.definition.BasicType) and
                t.value_type.typename in ['float', 'double', 'int8', 'uint8', 'int16', 'uint16', 'int32', 'uint32', 'int64', 'uint64']
            ):
                if len(field) == 0:
                    fieldstr = '[]'
                else:
                    assert fieldstr.startswith('array(')
                    prefix = "array('X', "
                    suffix = ')'
                    fieldstr = fieldstr[len(prefix):-len(suffix)]
            args.append(s[1:] + '=' + fieldstr)
        return '%s(%s)' % ('.'.join(typename), ', '.join(args))

    def __eq__(self, other):
        if not isinstance(other, self.__class__):
            return False
        if self.camera_info != other.camera_info:
            return False
        if self.image != other.image:
            return False
        if self.depth_image != other.depth_image:
            return False
        return True

    @classmethod
    def get_fields_and_field_types(cls):
        from copy import copy
        return copy(cls._fields_and_field_types)

    @builtins.property
    def camera_info(self):
        """Message field 'camera_info'."""
        return self._camera_info

    @camera_info.setter
    def camera_info(self, value):
        if __debug__:
            from sensor_msgs.msg import CameraInfo
            assert \
                isinstance(value, CameraInfo), \
                "The 'camera_info' field must be a sub message of type 'CameraInfo'"
        self._camera_info = value

    @builtins.property
    def image(self):
        """Message field 'image'."""
        return self._image

    @image.setter
    def image(self, value):
        if __debug__:
            from sensor_msgs.msg import Image
            assert \
                isinstance(value, Image), \
                "The 'image' field must be a sub message of type 'Image'"
        self._image = value

    @builtins.property
    def depth_image(self):
        """Message field 'depth_image'."""
        return self._depth_image

    @depth_image.setter
    def depth_image(self, value):
        if __debug__:
            from sensor_msgs.msg import Image
            assert \
                isinstance(value, Image), \
                "The 'depth_image' field must be a sub message of type 'Image'"
        self._depth_image = value


# Import statements for member types

# already imported above
# import builtins

# already imported above
# import rosidl_parser.definition


class Metaclass_Humancoordinates_Response(type):
    """Metaclass of message 'Humancoordinates_Response'."""

    _CREATE_ROS_MESSAGE = None
    _CONVERT_FROM_PY = None
    _CONVERT_TO_PY = None
    _DESTROY_ROS_MESSAGE = None
    _TYPE_SUPPORT = None

    __constants = {
    }

    @classmethod
    def __import_type_support__(cls):
        try:
            from rosidl_generator_py import import_type_support
            module = import_type_support('myinterfaces')
        except ImportError:
            import logging
            import traceback
            logger = logging.getLogger(
                'myinterfaces.srv.Humancoordinates_Response')
            logger.debug(
                'Failed to import needed modules for type support:\n' +
                traceback.format_exc())
        else:
            cls._CREATE_ROS_MESSAGE = module.create_ros_message_msg__srv__humancoordinates__response
            cls._CONVERT_FROM_PY = module.convert_from_py_msg__srv__humancoordinates__response
            cls._CONVERT_TO_PY = module.convert_to_py_msg__srv__humancoordinates__response
            cls._TYPE_SUPPORT = module.type_support_msg__srv__humancoordinates__response
            cls._DESTROY_ROS_MESSAGE = module.destroy_ros_message_msg__srv__humancoordinates__response

            from geometry_msgs.msg import Point
            if Point.__class__._TYPE_SUPPORT is None:
                Point.__class__.__import_type_support__()

    @classmethod
    def __prepare__(cls, name, bases, **kwargs):
        # list constant names here so that they appear in the help text of
        # the message class under "Data and other attributes defined here:"
        # as well as populate each message instance
        return {
        }


class Humancoordinates_Response(metaclass=Metaclass_Humancoordinates_Response):
    """Message class 'Humancoordinates_Response'."""

    __slots__ = [
        '_coordinate',
        '_response',
    ]

    _fields_and_field_types = {
        'coordinate': 'geometry_msgs/Point',
        'response': 'boolean',
    }

    SLOT_TYPES = (
        rosidl_parser.definition.NamespacedType(['geometry_msgs', 'msg'], 'Point'),  # noqa: E501
        rosidl_parser.definition.BasicType('boolean'),  # noqa: E501
    )

    def __init__(self, **kwargs):
        assert all('_' + key in self.__slots__ for key in kwargs.keys()), \
            'Invalid arguments passed to constructor: %s' % \
            ', '.join(sorted(k for k in kwargs.keys() if '_' + k not in self.__slots__))
        from geometry_msgs.msg import Point
        self.coordinate = kwargs.get('coordinate', Point())
        self.response = kwargs.get('response', bool())

    def __repr__(self):
        typename = self.__class__.__module__.split('.')
        typename.pop()
        typename.append(self.__class__.__name__)
        args = []
        for s, t in zip(self.__slots__, self.SLOT_TYPES):
            field = getattr(self, s)
            fieldstr = repr(field)
            # We use Python array type for fields that can be directly stored
            # in them, and "normal" sequences for everything else.  If it is
            # a type that we store in an array, strip off the 'array' portion.
            if (
                isinstance(t, rosidl_parser.definition.AbstractSequence) and
                isinstance(t.value_type, rosidl_parser.definition.BasicType) and
                t.value_type.typename in ['float', 'double', 'int8', 'uint8', 'int16', 'uint16', 'int32', 'uint32', 'int64', 'uint64']
            ):
                if len(field) == 0:
                    fieldstr = '[]'
                else:
                    assert fieldstr.startswith('array(')
                    prefix = "array('X', "
                    suffix = ')'
                    fieldstr = fieldstr[len(prefix):-len(suffix)]
            args.append(s[1:] + '=' + fieldstr)
        return '%s(%s)' % ('.'.join(typename), ', '.join(args))

    def __eq__(self, other):
        if not isinstance(other, self.__class__):
            return False
        if self.coordinate != other.coordinate:
            return False
        if self.response != other.response:
            return False
        return True

    @classmethod
    def get_fields_and_field_types(cls):
        from copy import copy
        return copy(cls._fields_and_field_types)

    @builtins.property
    def coordinate(self):
        """Message field 'coordinate'."""
        return self._coordinate

    @coordinate.setter
    def coordinate(self, value):
        if __debug__:
            from geometry_msgs.msg import Point
            assert \
                isinstance(value, Point), \
                "The 'coordinate' field must be a sub message of type 'Point'"
        self._coordinate = value

    @builtins.property
    def response(self):
        """Message field 'response'."""
        return self._response

    @response.setter
    def response(self, value):
        if __debug__:
            assert \
                isinstance(value, bool), \
                "The 'response' field must be of type 'bool'"
        self._response = value


class Metaclass_Humancoordinates(type):
    """Metaclass of service 'Humancoordinates'."""

    _TYPE_SUPPORT = None

    @classmethod
    def __import_type_support__(cls):
        try:
            from rosidl_generator_py import import_type_support
            module = import_type_support('myinterfaces')
        except ImportError:
            import logging
            import traceback
            logger = logging.getLogger(
                'myinterfaces.srv.Humancoordinates')
            logger.debug(
                'Failed to import needed modules for type support:\n' +
                traceback.format_exc())
        else:
            cls._TYPE_SUPPORT = module.type_support_srv__srv__humancoordinates

            from myinterfaces.srv import _humancoordinates
            if _humancoordinates.Metaclass_Humancoordinates_Request._TYPE_SUPPORT is None:
                _humancoordinates.Metaclass_Humancoordinates_Request.__import_type_support__()
            if _humancoordinates.Metaclass_Humancoordinates_Response._TYPE_SUPPORT is None:
                _humancoordinates.Metaclass_Humancoordinates_Response.__import_type_support__()


class Humancoordinates(metaclass=Metaclass_Humancoordinates):
    from myinterfaces.srv._humancoordinates import Humancoordinates_Request as Request
    from myinterfaces.srv._humancoordinates import Humancoordinates_Response as Response

    def __init__(self):
        raise NotImplementedError('Service classes can not be instantiated')
