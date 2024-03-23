// Generated by gencpp from file yolo/readyRequest.msg
// DO NOT EDIT!


#ifndef YOLO_MESSAGE_READYREQUEST_H
#define YOLO_MESSAGE_READYREQUEST_H


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
struct readyRequest_
{
  typedef readyRequest_<ContainerAllocator> Type;

  readyRequest_()
    : group(0)  {
    }
  readyRequest_(const ContainerAllocator& _alloc)
    : group(0)  {
  (void)_alloc;
    }



   typedef int64_t _group_type;
  _group_type group;





  typedef boost::shared_ptr< ::yolo::readyRequest_<ContainerAllocator> > Ptr;
  typedef boost::shared_ptr< ::yolo::readyRequest_<ContainerAllocator> const> ConstPtr;

}; // struct readyRequest_

typedef ::yolo::readyRequest_<std::allocator<void> > readyRequest;

typedef boost::shared_ptr< ::yolo::readyRequest > readyRequestPtr;
typedef boost::shared_ptr< ::yolo::readyRequest const> readyRequestConstPtr;

// constants requiring out of line definition



template<typename ContainerAllocator>
std::ostream& operator<<(std::ostream& s, const ::yolo::readyRequest_<ContainerAllocator> & v)
{
ros::message_operations::Printer< ::yolo::readyRequest_<ContainerAllocator> >::stream(s, "", v);
return s;
}


template<typename ContainerAllocator1, typename ContainerAllocator2>
bool operator==(const ::yolo::readyRequest_<ContainerAllocator1> & lhs, const ::yolo::readyRequest_<ContainerAllocator2> & rhs)
{
  return lhs.group == rhs.group;
}

template<typename ContainerAllocator1, typename ContainerAllocator2>
bool operator!=(const ::yolo::readyRequest_<ContainerAllocator1> & lhs, const ::yolo::readyRequest_<ContainerAllocator2> & rhs)
{
  return !(lhs == rhs);
}


} // namespace yolo

namespace ros
{
namespace message_traits
{





template <class ContainerAllocator>
struct IsMessage< ::yolo::readyRequest_<ContainerAllocator> >
  : TrueType
  { };

template <class ContainerAllocator>
struct IsMessage< ::yolo::readyRequest_<ContainerAllocator> const>
  : TrueType
  { };

template <class ContainerAllocator>
struct IsFixedSize< ::yolo::readyRequest_<ContainerAllocator> >
  : TrueType
  { };

template <class ContainerAllocator>
struct IsFixedSize< ::yolo::readyRequest_<ContainerAllocator> const>
  : TrueType
  { };

template <class ContainerAllocator>
struct HasHeader< ::yolo::readyRequest_<ContainerAllocator> >
  : FalseType
  { };

template <class ContainerAllocator>
struct HasHeader< ::yolo::readyRequest_<ContainerAllocator> const>
  : FalseType
  { };


template<class ContainerAllocator>
struct MD5Sum< ::yolo::readyRequest_<ContainerAllocator> >
{
  static const char* value()
  {
    return "ccdc8c98bacfaf09076383548856c042";
  }

  static const char* value(const ::yolo::readyRequest_<ContainerAllocator>&) { return value(); }
  static const uint64_t static_value1 = 0xccdc8c98bacfaf09ULL;
  static const uint64_t static_value2 = 0x076383548856c042ULL;
};

template<class ContainerAllocator>
struct DataType< ::yolo::readyRequest_<ContainerAllocator> >
{
  static const char* value()
  {
    return "yolo/readyRequest";
  }

  static const char* value(const ::yolo::readyRequest_<ContainerAllocator>&) { return value(); }
};

template<class ContainerAllocator>
struct Definition< ::yolo::readyRequest_<ContainerAllocator> >
{
  static const char* value()
  {
    return "# Ready Service\n"
"int64 group\n"
;
  }

  static const char* value(const ::yolo::readyRequest_<ContainerAllocator>&) { return value(); }
};

} // namespace message_traits
} // namespace ros

namespace ros
{
namespace serialization
{

  template<class ContainerAllocator> struct Serializer< ::yolo::readyRequest_<ContainerAllocator> >
  {
    template<typename Stream, typename T> inline static void allInOne(Stream& stream, T m)
    {
      stream.next(m.group);
    }

    ROS_DECLARE_ALLINONE_SERIALIZER
  }; // struct readyRequest_

} // namespace serialization
} // namespace ros

namespace ros
{
namespace message_operations
{

template<class ContainerAllocator>
struct Printer< ::yolo::readyRequest_<ContainerAllocator> >
{
  template<typename Stream> static void stream(Stream& s, const std::string& indent, const ::yolo::readyRequest_<ContainerAllocator>& v)
  {
    s << indent << "group: ";
    Printer<int64_t>::stream(s, indent + "  ", v.group);
  }
};

} // namespace message_operations
} // namespace ros

#endif // YOLO_MESSAGE_READYREQUEST_H
