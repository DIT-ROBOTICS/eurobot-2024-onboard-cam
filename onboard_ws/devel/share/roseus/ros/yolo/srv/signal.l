;; Auto-generated. Do not edit!


(when (boundp 'yolo::signal)
  (if (not (find-package "YOLO"))
    (make-package "YOLO"))
  (shadow 'signal (find-package "YOLO")))
(unless (find-package "YOLO::SIGNAL")
  (make-package "YOLO::SIGNAL"))
(unless (find-package "YOLO::SIGNALREQUEST")
  (make-package "YOLO::SIGNALREQUEST"))
(unless (find-package "YOLO::SIGNALRESPONSE")
  (make-package "YOLO::SIGNALRESPONSE"))

(in-package "ROS")





(defclass yolo::signalRequest
  :super ros::object
  :slots (_ready ))

(defmethod yolo::signalRequest
  (:init
   (&key
    ((:ready __ready) nil)
    )
   (send-super :init)
   (setq _ready __ready)
   self)
  (:ready
   (&optional (__ready :null))
   (if (not (eq __ready :null)) (setq _ready __ready)) _ready)
  (:serialization-length
   ()
   (+
    ;; bool _ready
    1
    ))
  (:serialize
   (&optional strm)
   (let ((s (if strm strm
              (make-string-output-stream (send self :serialization-length)))))
     ;; bool _ready
       (if _ready (write-byte -1 s) (write-byte 0 s))
     ;;
     (if (null strm) (get-output-stream-string s))))
  (:deserialize
   (buf &optional (ptr- 0))
   ;; bool _ready
     (setq _ready (not (= 0 (sys::peek buf ptr- :char)))) (incf ptr- 1)
   ;;
   self)
  )

(defclass yolo::signalResponse
  :super ros::object
  :slots (_success ))

(defmethod yolo::signalResponse
  (:init
   (&key
    ((:success __success) nil)
    )
   (send-super :init)
   (setq _success __success)
   self)
  (:success
   (&optional (__success :null))
   (if (not (eq __success :null)) (setq _success __success)) _success)
  (:serialization-length
   ()
   (+
    ;; bool _success
    1
    ))
  (:serialize
   (&optional strm)
   (let ((s (if strm strm
              (make-string-output-stream (send self :serialization-length)))))
     ;; bool _success
       (if _success (write-byte -1 s) (write-byte 0 s))
     ;;
     (if (null strm) (get-output-stream-string s))))
  (:deserialize
   (buf &optional (ptr- 0))
   ;; bool _success
     (setq _success (not (= 0 (sys::peek buf ptr- :char)))) (incf ptr- 1)
   ;;
   self)
  )

(defclass yolo::signal
  :super ros::object
  :slots ())

(setf (get yolo::signal :md5sum-) "e4630b5865ae6b0c6957bf21fb90b5a2")
(setf (get yolo::signal :datatype-) "yolo/signal")
(setf (get yolo::signal :request) yolo::signalRequest)
(setf (get yolo::signal :response) yolo::signalResponse)

(defmethod yolo::signalRequest
  (:response () (instance yolo::signalResponse :init)))

(setf (get yolo::signalRequest :md5sum-) "e4630b5865ae6b0c6957bf21fb90b5a2")
(setf (get yolo::signalRequest :datatype-) "yolo/signalRequest")
(setf (get yolo::signalRequest :definition-)
      "# Start Service
bool ready
---
bool success
")

(setf (get yolo::signalResponse :md5sum-) "e4630b5865ae6b0c6957bf21fb90b5a2")
(setf (get yolo::signalResponse :datatype-) "yolo/signalResponse")
(setf (get yolo::signalResponse :definition-)
      "# Start Service
bool ready
---
bool success
")



(provide :yolo/signal "e4630b5865ae6b0c6957bf21fb90b5a2")


