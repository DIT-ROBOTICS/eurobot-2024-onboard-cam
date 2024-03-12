
(cl:in-package :asdf)

(defsystem "yolo-msg"
  :depends-on (:roslisp-msg-protocol :roslisp-utils )
  :components ((:file "_package")
    (:file "yolomsg" :depends-on ("_package_yolomsg"))
    (:file "_package_yolomsg" :depends-on ("_package"))
  ))