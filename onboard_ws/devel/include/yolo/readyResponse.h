// Generated by gencpp from file yolo/readyResponse.msg
// DO NOT EDIT!


#ifndef YOLO_MESSAGE_READYRESPONSE_H
#define YOLO_MESSAGE_READYRESPONSE_H


#include <string>
#include <vector>
#include <memory>

#include <ros/types.h>
#include <ros/serialization.h>
#include <ros/builtin_message_traits.h>
#include <ros/message_operations.h>


namespace yolo
{
template <class ContainerAllocator>
struct readyResponse_
{
  typedef readyResponse_<ContainerAllocator> Type;

  readyResponse_()
    : success(false)  {
    }
  readyResponse_(const ContainerAllocator& _alloc)
    : success(false)  {
  (void)_alloc;
    }



   typedef uint8_t _success_type;
  _success_type success;





  typedef boost::shared_ptr< ::yolo::readyResponse_<ContainerAllocator> > Ptr;
  typedef boost::shared_ptr< ::yolo::readyResponse_<ContainerAllocator> const> ConstPtr;

}; // struct readyResponse_

typedef ::yolo::readyResponse_<std::allocator<void> > readyResponse;

typedef boost::shared_ptr< ::yolo::readyResponse > readyResponsePtr;
typedef boost::shared_ptr< ::yolo::readyResponse const> readyResponseConstPtr;

// constants requiring out of line definition



template<typename ContainerAllocator>
std::ostream& operator<<(std::ostream& s, const ::yolo::readyResponse_<ContainerAllocator> & v)
{
ros::message_operations::Printer< ::yolo::readyResponse_<ContainerAllocator> >::stream(s, "", v);
return s;
}


template<typename ContainerAllocator1, typename ContainerAllocator2>
bool operator==(const ::yolo::readyResponse_<ContainerAllocator1> & lhs, const ::yolo::readyResponse_<ContainerAllocator2> & rhs)
{
  return lhs.success == rhs.success;
}

template<typename ContainerAllocator1, typename ContainerAllocator2>
bool operator!=(const ::yolo::readyResponse_<ContainerAllocator1> & lhs, const ::yolo::readyResponse_<ContainerAllocator2> & rhs)
{
  return !(lhs == rhs);
}


} // namespace yolo

namespace ros
{
namespace message_traits
{





template <class ContainerAllocator>
struct IsMessage< ::yolo::readyResponse_<ContainerAllocator> >
  : TrueType
  { };

template <class ContainerAllocator>
struct IsMessage< ::yolo::readyResponse_<ContainerAllocator> const>
  : TrueType
  { };

template <class ContainerAllocator>
struct IsFixedSize< ::yolo::readyResponse_<ContainerAllocator> >
  : TrueType
  { };

template <class ContainerAllocator>
struct IsFixedSize< ::yolo::readyResponse_<ContainerAllocator> const>
  : TrueType
  { };

template <class ContainerAllocator>
struct HasHeader< ::yolo::readyResponse_<ContainerAllocator> >
  : FalseType
  { };

template <class ContainerAllocator>
struct HasHeader< ::yolo::readyResponse_<ContainerAllocator> const>
  : FalseType
  { };


template<class ContainerAllocator>
struct MD5Sum< ::yolo::readyResponse_<ContainerAllocator> >
{
  static const char* value()
  {
    return "358e233cde0c8a8bcfea4ce193f8fc15";
  }

  static const char* value(const ::yolo::readyResponse_<ContainerAllocator>&) { return value(); }
  static const uint64_t static_value1 = 0x358e233cde0c8a8bULL;
  static const uint64_t static_value2 = 0xcfea4ce193f8fc15ULL;
};

template<class ContainerAllocator>
struct DataType< ::yolo::readyResponse_<ContainerAllocator> >
{
  static const char* value()
  {
    return "yolo/readyResponse";
  }

  static const char* value(const ::yolo::readyResponse_<ContainerAllocator>&) { return value(); }
};

template<class ContainerAllocator>
struct Definition< ::yolo::readyResponse_<ContainerAllocator> >
{
  static const char* value()
  {
    return "bool success\n"
;
  }

  static const char* value(const ::yolo::readyResponse_<ContainerAllocator>&) { return value(); }
};

} // namespace message_traits
} // namespace ros

namespace ros
{
namespace serialization
{

  template<class ContainerAllocator> struct Serializer< ::yolo::readyResponse_<ContainerAllocator> >
  {
    template<typename Stream, typename T> inline static void allInOne(Stream& stream, T m)
    {
      stream.next(m.success);
    }

    ROS_DECLARE_ALLINONE_SERIALIZER
  }; // struct readyResponse_

} // namespace serialization
} // namespace ros

namespace ros
{
namespace message_operations
{

template<class ContainerAllocator>
struct Printer< ::yolo::readyResponse_<ContainerAllocator> >
{
  template<typename Stream> static void stream(Stream& s, const std::string& indent, const ::yolo::readyResponse_<ContainerAllocator>& v)
  {
    s << indent << "success: ";
    Printer<uint8_t>::stream(s, indent + "  ", v.success);
  }
};

} // namespace message_operations
} // namespace ros

#endif // YOLO_MESSAGE_READYRESPONSE_H
