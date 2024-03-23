; Auto-generated. Do not edit!


(cl:in-package yolo-srv)


;//! \htmlinclude ready-request.msg.html

(cl:defclass <ready-request> (roslisp-msg-protocol:ros-message)
  ((group
    :reader group
    :initarg :group
    :type cl:integer
    :initform 0))
)

(cl:defclass ready-request (<ready-request>)
  ())

(cl:defmethod cl:initialize-instance :after ((m <ready-request>) cl:&rest args)
  (cl:declare (cl:ignorable args))
  (cl:unless (cl:typep m 'ready-request)
    (roslisp-msg-protocol:msg-deprecation-warning "using old message class name yolo-srv:<ready-request> is deprecated: use yolo-srv:ready-request instead.")))

(cl:ensure-generic-function 'group-val :lambda-list '(m))
(cl:defmethod group-val ((m <ready-request>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader yolo-srv:group-val is deprecated.  Use yolo-srv:group instead.")
  (group m))
(cl:defmethod roslisp-msg-protocol:serialize ((msg <ready-request>) ostream)
  "Serializes a message object of type '<ready-request>"
  (cl:let* ((signed (cl:slot-value msg 'group)) (unsigned (cl:if (cl:< signed 0) (cl:+ signed 18446744073709551616) signed)))
    (cl:write-byte (cl:ldb (cl:byte 8 0) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 32) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 40) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 48) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 56) unsigned) ostream)
    )
)
(cl:defmethod roslisp-msg-protocol:deserialize ((msg <ready-request>) istream)
  "Deserializes a message object of type '<ready-request>"
    (cl:let ((unsigned 0))
      (cl:setf (cl:ldb (cl:byte 8 0) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 32) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 40) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 48) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 56) unsigned) (cl:read-byte istream))
      (cl:setf (cl:slot-value msg 'group) (cl:if (cl:< unsigned 9223372036854775808) unsigned (cl:- unsigned 18446744073709551616))))
  msg
)
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql '<ready-request>)))
  "Returns string type for a service object of type '<ready-request>"
  "yolo/readyRequest")
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql 'ready-request)))
  "Returns string type for a service object of type 'ready-request"
  "yolo/readyRequest")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql '<ready-request>)))
  "Returns md5sum for a message object of type '<ready-request>"
  "da5a7aac6c5f3883c2c81418dc34dfa3")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql 'ready-request)))
  "Returns md5sum for a message object of type 'ready-request"
  "da5a7aac6c5f3883c2c81418dc34dfa3")
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql '<ready-request>)))
  "Returns full string definition for message of type '<ready-request>"
  (cl:format cl:nil "# Ready Service~%int64 group~%~%~%"))
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql 'ready-request)))
  "Returns full string definition for message of type 'ready-request"
  (cl:format cl:nil "# Ready Service~%int64 group~%~%~%"))
(cl:defmethod roslisp-msg-protocol:serialization-length ((msg <ready-request>))
  (cl:+ 0
     8
))
(cl:defmethod roslisp-msg-protocol:ros-message-to-list ((msg <ready-request>))
  "Converts a ROS message object to a list"
  (cl:list 'ready-request
    (cl:cons ':group (group msg))
))
;//! \htmlinclude ready-response.msg.html

(cl:defclass <ready-response> (roslisp-msg-protocol:ros-message)
  ((success
    :reader success
    :initarg :success
    :type cl:boolean
    :initform cl:nil))
)

(cl:defclass ready-response (<ready-response>)
  ())

(cl:defmethod cl:initialize-instance :after ((m <ready-response>) cl:&rest args)
  (cl:declare (cl:ignorable args))
  (cl:unless (cl:typep m 'ready-response)
    (roslisp-msg-protocol:msg-deprecation-warning "using old message class name yolo-srv:<ready-response> is deprecated: use yolo-srv:ready-response instead.")))

(cl:ensure-generic-function 'success-val :lambda-list '(m))
(cl:defmethod success-val ((m <ready-response>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader yolo-srv:success-val is deprecated.  Use yolo-srv:success instead.")
  (success m))
(cl:defmethod roslisp-msg-protocol:serialize ((msg <ready-response>) ostream)
  "Serializes a message object of type '<ready-response>"
  (cl:write-byte (cl:ldb (cl:byte 8 0) (cl:if (cl:slot-value msg 'success) 1 0)) ostream)
)
(cl:defmethod roslisp-msg-protocol:deserialize ((msg <ready-response>) istream)
  "Deserializes a message object of type '<ready-response>"
    (cl:setf (cl:slot-value msg 'success) (cl:not (cl:zerop (cl:read-byte istream))))
  msg
)
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql '<ready-response>)))
  "Returns string type for a service object of type '<ready-response>"
  "yolo/readyResponse")
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql 'ready-response)))
  "Returns string type for a service object of type 'ready-response"
  "yolo/readyResponse")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql '<ready-response>)))
  "Returns md5sum for a message object of type '<ready-response>"
  "da5a7aac6c5f3883c2c81418dc34dfa3")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql 'ready-response)))
  "Returns md5sum for a message object of type 'ready-response"
  "da5a7aac6c5f3883c2c81418dc34dfa3")
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql '<ready-response>)))
  "Returns full string definition for message of type '<ready-response>"
  (cl:format cl:nil "bool success~%~%~%"))
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql 'ready-response)))
  "Returns full string definition for message of type 'ready-response"
  (cl:format cl:nil "bool success~%~%~%"))
(cl:defmethod roslisp-msg-protocol:serialization-length ((msg <ready-response>))
  (cl:+ 0
     1
))
(cl:defmethod roslisp-msg-protocol:ros-message-to-list ((msg <ready-response>))
  "Converts a ROS message object to a list"
  (cl:list 'ready-response
    (cl:cons ':success (success msg))
))
(cl:defmethod roslisp-msg-protocol:service-request-type ((msg (cl:eql 'ready)))
  'ready-request)
(cl:defmethod roslisp-msg-protocol:service-response-type ((msg (cl:eql 'ready)))
  'ready-response)
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql 'ready)))
  "Returns string type for a service object of type '<ready>"
  "yolo/ready")