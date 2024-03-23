;; Auto-generated. Do not edit!


(when (boundp 'yolo::ready)
  (if (not (find-package "YOLO"))
    (make-package "YOLO"))
  (shadow 'ready (find-package "YOLO")))
(unless (find-package "YOLO::READY")
  (make-package "YOLO::READY"))
(unless (find-package "YOLO::READYREQUEST")
  (make-package "YOLO::READYREQUEST"))
(unless (find-package "YOLO::READYRESPONSE")
  (make-package "YOLO::READYRESPONSE"))

(in-package "ROS")





(defclass yolo::readyRequest
  :super ros::object
  :slots (_group ))

(defmethod yolo::readyRequest
  (:init
   (&key
    ((:group __group) 0)
    )
   (send-super :init)
   (setq _group (round __group))
   self)
  (:group
   (&optional __group)
   (if __group (setq _group __group)) _group)
  (:serialization-length
   ()
   (+
    ;; int64 _group
    8
    ))
  (:serialize
   (&optional strm)
   (let ((s (if strm strm
              (make-string-output-stream (send self :serialization-length)))))
     ;; int64 _group
#+(or :alpha :irix6 :x86_64)
       (progn (sys::poke _group (send s :buffer) (send s :count) :long) (incf (stream-count s) 8))
#-(or :alpha :irix6 :x86_64)
       (cond ((and (class _group) (= (length (_group . bv)) 2)) ;; bignum
              (write-long (ash (elt (_group . bv) 0) 0) s)
              (write-long (ash (elt (_group . bv) 1) -1) s))
             ((and (class _group) (= (length (_group . bv)) 1)) ;; big1
              (write-long (elt (_group . bv) 0) s)
              (write-long (if (>= _group 0) 0 #xffffffff) s))
             (t                                         ;; integer
              (write-long _group s)(write-long (if (>= _group 0) 0 #xffffffff) s)))
     ;;
     (if (null strm) (get-output-stream-string s))))
  (:deserialize
   (buf &optional (ptr- 0))
   ;; int64 _group
#+(or :alpha :irix6 :x86_64)
      (setf _group (prog1 (sys::peek buf ptr- :long) (incf ptr- 8)))
#-(or :alpha :irix6 :x86_64)
      (setf _group (let ((b0 (prog1 (sys::peek buf ptr- :integer) (incf ptr- 4)))
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

(defclass yolo::readyResponse
  :super ros::object
  :slots (_success ))

(defmethod yolo::readyResponse
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

(defclass yolo::ready
  :super ros::object
  :slots ())

(setf (get yolo::ready :md5sum-) "da5a7aac6c5f3883c2c81418dc34dfa3")
(setf (get yolo::ready :datatype-) "yolo/ready")
(setf (get yolo::ready :request) yolo::readyRequest)
(setf (get yolo::ready :response) yolo::readyResponse)

(defmethod yolo::readyRequest
  (:response () (instance yolo::readyResponse :init)))

(setf (get yolo::readyRequest :md5sum-) "da5a7aac6c5f3883c2c81418dc34dfa3")
(setf (get yolo::readyRequest :datatype-) "yolo/readyRequest")
(setf (get yolo::readyRequest :definition-)
      "# Ready Service
int64 group
---
bool success
")

(setf (get yolo::readyResponse :md5sum-) "da5a7aac6c5f3883c2c81418dc34dfa3")
(setf (get yolo::readyResponse :datatype-) "yolo/readyResponse")
(setf (get yolo::readyResponse :definition-)
      "# Ready Service
int64 group
---
bool success
")



(provide :yolo/ready "da5a7aac6c5f3883c2c81418dc34dfa3")


