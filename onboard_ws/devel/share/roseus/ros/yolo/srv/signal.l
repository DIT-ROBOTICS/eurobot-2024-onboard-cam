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
  :slots (_signal ))

(defmethod yolo::signalRequest
  (:init
   (&key
    ((:signal __signal) 0)
    )
   (send-super :init)
   (setq _signal (round __signal))
   self)
  (:signal
   (&optional __signal)
   (if __signal (setq _signal __signal)) _signal)
  (:serialization-length
   ()
   (+
    ;; int64 _signal
    8
    ))
  (:serialize
   (&optional strm)
   (let ((s (if strm strm
              (make-string-output-stream (send self :serialization-length)))))
     ;; int64 _signal
#+(or :alpha :irix6 :x86_64)
       (progn (sys::poke _signal (send s :buffer) (send s :count) :long) (incf (stream-count s) 8))
#-(or :alpha :irix6 :x86_64)
       (cond ((and (class _signal) (= (length (_signal . bv)) 2)) ;; bignum
              (write-long (ash (elt (_signal . bv) 0) 0) s)
              (write-long (ash (elt (_signal . bv) 1) -1) s))
             ((and (class _signal) (= (length (_signal . bv)) 1)) ;; big1
              (write-long (elt (_signal . bv) 0) s)
              (write-long (if (>= _signal 0) 0 #xffffffff) s))
             (t                                         ;; integer
              (write-long _signal s)(write-long (if (>= _signal 0) 0 #xffffffff) s)))
     ;;
     (if (null strm) (get-output-stream-string s))))
  (:deserialize
   (buf &optional (ptr- 0))
   ;; int64 _signal
#+(or :alpha :irix6 :x86_64)
      (setf _signal (prog1 (sys::peek buf ptr- :long) (incf ptr- 8)))
#-(or :alpha :irix6 :x86_64)
      (setf _signal (let ((b0 (prog1 (sys::peek buf ptr- :integer) (incf ptr- 4)))
                  (b1 (prog1 (sys::peek buf ptr- :integer) (incf ptr- 4))))
              (cond ((= b1 -1) b0)
                     ((and (= b1  0)
                           (<= lisp::most-negative-fixnum b0 lisp::most-positive-fixnum))
                      b0)
                    ((= b1  0) (make-instance bignum :size 1 :bv (integer-vector b0)))
                    (t (make-instance bignum :size 2 :bv (integer-vector b0 (ash b1 1)))))))
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

(setf (get yolo::signal :md5sum-) "f949f7237e30347573901ebcc4b2ea5e")
(setf (get yolo::signal :datatype-) "yolo/signal")
(setf (get yolo::signal :request) yolo::signalRequest)
(setf (get yolo::signal :response) yolo::signalResponse)

(defmethod yolo::signalRequest
  (:response () (instance yolo::signalResponse :init)))

(setf (get yolo::signalRequest :md5sum-) "f949f7237e30347573901ebcc4b2ea5e")
(setf (get yolo::signalRequest :datatype-) "yolo/signalRequest")
(setf (get yolo::signalRequest :definition-)
      "# onboard cam Service
int64 signal
---
bool success
")

(setf (get yolo::signalResponse :md5sum-) "f949f7237e30347573901ebcc4b2ea5e")
(setf (get yolo::signalResponse :datatype-) "yolo/signalResponse")
(setf (get yolo::signalResponse :definition-)
      "# onboard cam Service
int64 signal
---
bool success
")



(provide :yolo/signal "f949f7237e30347573901ebcc4b2ea5e")


