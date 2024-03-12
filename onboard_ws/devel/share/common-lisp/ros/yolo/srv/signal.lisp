; Auto-generated. Do not edit!


(cl:in-package yolo-srv)


;//! \htmlinclude signal-request.msg.html

(cl:defclass <signal-request> (roslisp-msg-protocol:ros-message)
  ((ready
    :reader ready
    :initarg :ready
    :type cl:boolean
    :initform cl:nil))
)

(cl:defclass signal-request (<signal-request>)
  ())

(cl:defmethod cl:initialize-instance :after ((m <signal-request>) cl:&rest args)
  (cl:declare (cl:ignorable args))
  (cl:unless (cl:typep m 'signal-request)
    (roslisp-msg-protocol:msg-deprecation-warning "using old message class name yolo-srv:<signal-request> is deprecated: use yolo-srv:signal-request instead.")))

(cl:ensure-generic-function 'ready-val :lambda-list '(m))
(cl:defmethod ready-val ((m <signal-request>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader yolo-srv:ready-val is deprecated.  Use yolo-srv:ready instead.")
  (ready m))
(cl:defmethod roslisp-msg-protocol:serialize ((msg <signal-request>) ostream)
  "Serializes a message object of type '<signal-request>"
  (cl:write-byte (cl:ldb (cl:byte 8 0) (cl:if (cl:slot-value msg 'ready) 1 0)) ostream)
)
(cl:defmethod roslisp-msg-protocol:deserialize ((msg <signal-request>) istream)
  "Deserializes a message object of type '<signal-request>"
    (cl:setf (cl:slot-value msg 'ready) (cl:not (cl:zerop (cl:read-byte istream))))
  msg
)
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql '<signal-request>)))
  "Returns string type for a service object of type '<signal-request>"
  "yolo/signalRequest")
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql 'signal-request)))
  "Returns string type for a service object of type 'signal-request"
  "yolo/signalRequest")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql '<signal-request>)))
  "Returns md5sum for a message object of type '<signal-request>"
  "e4630b5865ae6b0c6957bf21fb90b5a2")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql 'signal-request)))
  "Returns md5sum for a message object of type 'signal-request"
  "e4630b5865ae6b0c6957bf21fb90b5a2")
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql '<signal-request>)))
  "Returns full string definition for message of type '<signal-request>"
  (cl:format cl:nil "# Start Service~%bool ready~%~%~%"))
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql 'signal-request)))
  "Returns full string definition for message of type 'signal-request"
  (cl:format cl:nil "# Start Service~%bool ready~%~%~%"))
(cl:defmethod roslisp-msg-protocol:serialization-length ((msg <signal-request>))
  (cl:+ 0
     1
))
(cl:defmethod roslisp-msg-protocol:ros-message-to-list ((msg <signal-request>))
  "Converts a ROS message object to a list"
  (cl:list 'signal-request
    (cl:cons ':ready (ready msg))
))
;//! \htmlinclude signal-response.msg.html

(cl:defclass <signal-response> (roslisp-msg-protocol:ros-message)
  ((success
    :reader success
    :initarg :success
    :type cl:boolean
    :initform cl:nil))
)

(cl:defclass signal-response (<signal-response>)
  ())

(cl:defmethod cl:initialize-instance :after ((m <signal-response>) cl:&rest args)
  (cl:declare (cl:ignorable args))
  (cl:unless (cl:typep m 'signal-response)
    (roslisp-msg-protocol:msg-deprecation-warning "using old message class name yolo-srv:<signal-response> is deprecated: use yolo-srv:signal-response instead.")))

(cl:ensure-generic-function 'success-val :lambda-list '(m))
(cl:defmethod success-val ((m <signal-response>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader yolo-srv:success-val is deprecated.  Use yolo-srv:success instead.")
  (success m))
(cl:defmethod roslisp-msg-protocol:serialize ((msg <signal-response>) ostream)
  "Serializes a message object of type '<signal-response>"
  (cl:write-byte (cl:ldb (cl:byte 8 0) (cl:if (cl:slot-value msg 'success) 1 0)) ostream)
)
(cl:defmethod roslisp-msg-protocol:deserialize ((msg <signal-response>) istream)
  "Deserializes a message object of type '<signal-response>"
    (cl:setf (cl:slot-value msg 'success) (cl:not (cl:zerop (cl:read-byte istream))))
  msg
)
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql '<signal-response>)))
  "Returns string type for a service object of type '<signal-response>"
  "yolo/signalResponse")
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql 'signal-response)))
  "Returns string type for a service object of type 'signal-response"
  "yolo/signalResponse")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql '<signal-response>)))
  "Returns md5sum for a message object of type '<signal-response>"
  "e4630b5865ae6b0c6957bf21fb90b5a2")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql 'signal-response)))
  "Returns md5sum for a message object of type 'signal-response"
  "e4630b5865ae6b0c6957bf21fb90b5a2")
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql '<signal-response>)))
  "Returns full string definition for message of type '<signal-response>"
  (cl:format cl:nil "bool success~%~%~%"))
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql 'signal-response)))
  "Returns full string definition for message of type 'signal-response"
  (cl:format cl:nil "bool success~%~%~%"))
(cl:defmethod roslisp-msg-protocol:serialization-length ((msg <signal-response>))
  (cl:+ 0
     1
))
(cl:defmethod roslisp-msg-protocol:ros-message-to-list ((msg <signal-response>))
  "Converts a ROS message object to a list"
  (cl:list 'signal-response
    (cl:cons ':success (success msg))
))
(cl:defmethod roslisp-msg-protocol:service-request-type ((msg (cl:eql 'signal)))
  'signal-request)
(cl:defmethod roslisp-msg-protocol:service-response-type ((msg (cl:eql 'signal)))
  'signal-response)
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql 'signal)))
  "Returns string type for a service object of type '<signal>"
  "yolo/signal")