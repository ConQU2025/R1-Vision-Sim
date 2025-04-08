;; Auto-generated. Do not edit!


(when (boundp 'conqu::ByteArray)
  (if (not (find-package "CONQU"))
    (make-package "CONQU"))
  (shadow 'ByteArray (find-package "CONQU")))
(unless (find-package "CONQU::BYTEARRAY")
  (make-package "CONQU::BYTEARRAY"))

(in-package "ROS")
;;//! \htmlinclude ByteArray.msg.html


(defclass conqu::ByteArray
  :super ros::object
  :slots (_data ))

(defmethod conqu::ByteArray
  (:init
   (&key
    ((:data __data) (make-array 10 :initial-element 0 :element-type :char))
    )
   (send-super :init)
   (setq _data __data)
   self)
  (:data
   (&optional __data)
   (if __data (setq _data __data)) _data)
  (:serialization-length
   ()
   (+
    ;; uint8[10] _data
    (* 1    10)
    ))
  (:serialize
   (&optional strm)
   (let ((s (if strm strm
              (make-string-output-stream (send self :serialization-length)))))
     ;; uint8[10] _data
     (princ _data s)
     ;;
     (if (null strm) (get-output-stream-string s))))
  (:deserialize
   (buf &optional (ptr- 0))
   ;; uint8[10] _data
   (setq _data (make-array 10 :element-type :char))
   (replace _data buf :start2 ptr-) (incf ptr- 10)
   ;;
   self)
  )

(setf (get conqu::ByteArray :md5sum-) "0c05a05733f13fb160c661ca1798fdba")
(setf (get conqu::ByteArray :datatype-) "conqu/ByteArray")
(setf (get conqu::ByteArray :definition-)
      "uint8[10] data
")



(provide :conqu/ByteArray "0c05a05733f13fb160c661ca1798fdba")


