
(cl:in-package :asdf)

(defsystem "yolo-srv"
  :depends-on (:roslisp-msg-protocol :roslisp-utils )
  :components ((:file "_package")
    (:file "ready" :depends-on ("_package_ready"))
    (:file "_package_ready" :depends-on ("_package"))
    (:file "signal" :depends-on ("_package_signal"))
    (:file "_package_signal" :depends-on ("_package"))
  ))