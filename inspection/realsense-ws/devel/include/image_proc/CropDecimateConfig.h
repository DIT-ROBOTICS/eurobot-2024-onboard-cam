//#line 2 "/opt/ros/noetic/share/dynamic_reconfigure/cmake/../templates/ConfigType.h.template"
// *********************************************************
//
// File autogenerated for the image_proc package
// by the dynamic_reconfigure package.
// Please do not edit.
//
// ********************************************************/

#ifndef __image_proc__CROPDECIMATECONFIG_H__
#define __image_proc__CROPDECIMATECONFIG_H__

#if __cplusplus >= 201103L
#define DYNAMIC_RECONFIGURE_FINAL final
#else
#define DYNAMIC_RECONFIGURE_FINAL
#endif

#include <dynamic_reconfigure/config_tools.h>
#include <limits>
#include <ros/node_handle.h>
#include <dynamic_reconfigure/ConfigDescription.h>
#include <dynamic_reconfigure/ParamDescription.h>
#include <dynamic_reconfigure/Group.h>
#include <dynamic_reconfigure/config_init_mutex.h>
#include <boost/any.hpp>

namespace image_proc
{
  class CropDecimateConfigStatics;

  class CropDecimateConfig
  {
  public:
    class AbstractParamDescription : public dynamic_reconfigure::ParamDescription
    {
    public:
      AbstractParamDescription(std::string n, std::string t, uint32_t l,
          std::string d, std::string e)
      {
        name = n;
        type = t;
        level = l;
        description = d;
        edit_method = e;
      }
      virtual ~AbstractParamDescription() = default;

      virtual void clamp(CropDecimateConfig &config, const CropDecimateConfig &max, const CropDecimateConfig &min) const = 0;
      virtual void calcLevel(uint32_t &level, const CropDecimateConfig &config1, const CropDecimateConfig &config2) const = 0;
      virtual void fromServer(const ros::NodeHandle &nh, CropDecimateConfig &config) const = 0;
      virtual void toServer(const ros::NodeHandle &nh, const CropDecimateConfig &config) const = 0;
      virtual bool fromMessage(const dynamic_reconfigure::Config &msg, CropDecimateConfig &config) const = 0;
      virtual void toMessage(dynamic_reconfigure::Config &msg, const CropDecimateConfig &config) const = 0;
      virtual void getValue(const CropDecimateConfig &config, boost::any &val) const = 0;
    };

    typedef boost::shared_ptr<AbstractParamDescription> AbstractParamDescriptionPtr;
    typedef boost::shared_ptr<const AbstractParamDescription> AbstractParamDescriptionConstPtr;

    // Final keyword added to class because it has virtual methods and inherits
    // from a class with a non-virtual destructor.
    template <class T>
    class ParamDescription DYNAMIC_RECONFIGURE_FINAL : public AbstractParamDescription
    {
    public:
      ParamDescription(std::string a_name, std::string a_type, uint32_t a_level,
          std::string a_description, std::string a_edit_method, T CropDecimateConfig::* a_f) :
        AbstractParamDescription(a_name, a_type, a_level, a_description, a_edit_method),
        field(a_f)
      {}

      T CropDecimateConfig::* field;

      virtual void clamp(CropDecimateConfig &config, const CropDecimateConfig &max, const CropDecimateConfig &min) const override
      {
        if (config.*field > max.*field)
          config.*field = max.*field;

        if (config.*field < min.*field)
          config.*field = min.*field;
      }

      virtual void calcLevel(uint32_t &comb_level, const CropDecimateConfig &config1, const CropDecimateConfig &config2) const override
      {
        if (config1.*field != config2.*field)
          comb_level |= level;
      }

      virtual void fromServer(const ros::NodeHandle &nh, CropDecimateConfig &config) const override
      {
        nh.getParam(name, config.*field);
      }

      virtual void toServer(const ros::NodeHandle &nh, const CropDecimateConfig &config) const override
      {
        nh.setParam(name, config.*field);
      }

      virtual bool fromMessage(const dynamic_reconfigure::Config &msg, CropDecimateConfig &config) const override
      {
        return dynamic_reconfigure::ConfigTools::getParameter(msg, name, config.*field);
      }

      virtual void toMessage(dynamic_reconfigure::Config &msg, const CropDecimateConfig &config) const override
      {
        dynamic_reconfigure::ConfigTools::appendParameter(msg, name, config.*field);
      }

      virtual void getValue(const CropDecimateConfig &config, boost::any &val) const override
      {
        val = config.*field;
      }
    };

    class AbstractGroupDescription : public dynamic_reconfigure::Group
    {
      public:
      AbstractGroupDescription(std::string n, std::string t, int p, int i, bool s)
      {
        name = n;
        type = t;
        parent = p;
        state = s;
        id = i;
      }

      virtual ~AbstractGroupDescription() = default;

      std::vector<AbstractParamDescriptionConstPtr> abstract_parameters;
      bool state;

      virtual void toMessage(dynamic_reconfigure::Config &msg, const boost::any &config) const = 0;
      virtual bool fromMessage(const dynamic_reconfigure::Config &msg, boost::any &config) const =0;
      virtual void updateParams(boost::any &cfg, CropDecimateConfig &top) const= 0;
      virtual void setInitialState(boost::any &cfg) const = 0;


      void convertParams()
      {
        for(std::vector<AbstractParamDescriptionConstPtr>::const_iterator i = abstract_parameters.begin(); i != abstract_parameters.end(); ++i)
        {
          parameters.push_back(dynamic_reconfigure::ParamDescription(**i));
        }
      }
    };

    typedef boost::shared_ptr<AbstractGroupDescription> AbstractGroupDescriptionPtr;
    typedef boost::shared_ptr<const AbstractGroupDescription> AbstractGroupDescriptionConstPtr;

    // Final keyword added to class because it has virtual methods and inherits
    // from a class with a non-virtual destructor.
    template<class T, class PT>
    class GroupDescription DYNAMIC_RECONFIGURE_FINAL : public AbstractGroupDescription
    {
    public:
      GroupDescription(std::string a_name, std::string a_type, int a_parent, int a_id, bool a_s, T PT::* a_f) : AbstractGroupDescription(a_name, a_type, a_parent, a_id, a_s), field(a_f)
      {
      }

      GroupDescription(const GroupDescription<T, PT>& g): AbstractGroupDescription(g.name, g.type, g.parent, g.id, g.state), field(g.field), groups(g.groups)
      {
        parameters = g.parameters;
        abstract_parameters = g.abstract_parameters;
      }

      virtual bool fromMessage(const dynamic_reconfigure::Config &msg, boost::any &cfg) const override
      {
        PT* config = boost::any_cast<PT*>(cfg);
        if(!dynamic_reconfigure::ConfigTools::getGroupState(msg, name, (*config).*field))
          return false;

        for(std::vector<AbstractGroupDescriptionConstPtr>::const_iterator i = groups.begin(); i != groups.end(); ++i)
        {
          boost::any n = &((*config).*field);
          if(!(*i)->fromMessage(msg, n))
            return false;
        }

        return true;
      }

      virtual void setInitialState(boost::any &cfg) const override
      {
        PT* config = boost::any_cast<PT*>(cfg);
        T* group = &((*config).*field);
        group->state = state;

        for(std::vector<AbstractGroupDescriptionConstPtr>::const_iterator i = groups.begin(); i != groups.end(); ++i)
        {
          boost::any n = boost::any(&((*config).*field));
          (*i)->setInitialState(n);
        }

      }

      virtual void updateParams(boost::any &cfg, CropDecimateConfig &top) const override
      {
        PT* config = boost::any_cast<PT*>(cfg);

        T* f = &((*config).*field);
        f->setParams(top, abstract_parameters);

        for(std::vector<AbstractGroupDescriptionConstPtr>::const_iterator i = groups.begin(); i != groups.end(); ++i)
        {
          boost::any n = &((*config).*field);
          (*i)->updateParams(n, top);
        }
      }

      virtual void toMessage(dynamic_reconfigure::Config &msg, const boost::any &cfg) const override
      {
        const PT config = boost::any_cast<PT>(cfg);
        dynamic_reconfigure::ConfigTools::appendGroup<T>(msg, name, id, parent, config.*field);

        for(std::vector<AbstractGroupDescriptionConstPtr>::const_iterator i = groups.begin(); i != groups.end(); ++i)
        {
          (*i)->toMessage(msg, config.*field);
        }
      }

      T PT::* field;
      std::vector<CropDecimateConfig::AbstractGroupDescriptionConstPtr> groups;
    };

class DEFAULT
{
  public:
    DEFAULT()
    {
      state = true;
      name = "Default";
    }

    void setParams(CropDecimateConfig &config, const std::vector<AbstractParamDescriptionConstPtr> params)
    {
      for (std::vector<AbstractParamDescriptionConstPtr>::const_iterator _i = params.begin(); _i != params.end(); ++_i)
      {
        boost::any val;
        (*_i)->getValue(config, val);

        if("decimation_x"==(*_i)->name){decimation_x = boost::any_cast<int>(val);}
        if("decimation_y"==(*_i)->name){decimation_y = boost::any_cast<int>(val);}
        if("x_offset"==(*_i)->name){x_offset = boost::any_cast<int>(val);}
        if("y_offset"==(*_i)->name){y_offset = boost::any_cast<int>(val);}
        if("width"==(*_i)->name){width = boost::any_cast<int>(val);}
        if("height"==(*_i)->name){height = boost::any_cast<int>(val);}
        if("interpolation"==(*_i)->name){interpolation = boost::any_cast<int>(val);}
      }
    }

    int decimation_x;
int decimation_y;
int x_offset;
int y_offset;
int width;
int height;
int interpolation;

    bool state;
    std::string name;

    
}groups;



//#line 291 "/opt/ros/noetic/lib/python3/dist-packages/dynamic_reconfigure/parameter_generator_catkin.py"
      int decimation_x;
//#line 291 "/opt/ros/noetic/lib/python3/dist-packages/dynamic_reconfigure/parameter_generator_catkin.py"
      int decimation_y;
//#line 291 "/opt/ros/noetic/lib/python3/dist-packages/dynamic_reconfigure/parameter_generator_catkin.py"
      int x_offset;
//#line 291 "/opt/ros/noetic/lib/python3/dist-packages/dynamic_reconfigure/parameter_generator_catkin.py"
      int y_offset;
//#line 291 "/opt/ros/noetic/lib/python3/dist-packages/dynamic_reconfigure/parameter_generator_catkin.py"
      int width;
//#line 291 "/opt/ros/noetic/lib/python3/dist-packages/dynamic_reconfigure/parameter_generator_catkin.py"
      int height;
//#line 291 "/opt/ros/noetic/lib/python3/dist-packages/dynamic_reconfigure/parameter_generator_catkin.py"
      int interpolation;
//#line 231 "/opt/ros/noetic/share/dynamic_reconfigure/cmake/../templates/ConfigType.h.template"

    bool __fromMessage__(dynamic_reconfigure::Config &msg)
    {
      const std::vector<AbstractParamDescriptionConstPtr> &__param_descriptions__ = __getParamDescriptions__();
      const std::vector<AbstractGroupDescriptionConstPtr> &__group_descriptions__ = __getGroupDescriptions__();

      int count = 0;
      for (std::vector<AbstractParamDescriptionConstPtr>::const_iterator i = __param_descriptions__.begin(); i != __param_descriptions__.end(); ++i)
        if ((*i)->fromMessage(msg, *this))
          count++;

      for (std::vector<AbstractGroupDescriptionConstPtr>::const_iterator i = __group_descriptions__.begin(); i != __group_descriptions__.end(); i ++)
      {
        if ((*i)->id == 0)
        {
          boost::any n = boost::any(this);
          (*i)->updateParams(n, *this);
          (*i)->fromMessage(msg, n);
        }
      }

      if (count != dynamic_reconfigure::ConfigTools::size(msg))
      {
        ROS_ERROR("CropDecimateConfig::__fromMessage__ called with an unexpected parameter.");
        ROS_ERROR("Booleans:");
        for (unsigned int i = 0; i < msg.bools.size(); i++)
          ROS_ERROR("  %s", msg.bools[i].name.c_str());
        ROS_ERROR("Integers:");
        for (unsigned int i = 0; i < msg.ints.size(); i++)
          ROS_ERROR("  %s", msg.ints[i].name.c_str());
        ROS_ERROR("Doubles:");
        for (unsigned int i = 0; i < msg.doubles.size(); i++)
          ROS_ERROR("  %s", msg.doubles[i].name.c_str());
        ROS_ERROR("Strings:");
        for (unsigned int i = 0; i < msg.strs.size(); i++)
          ROS_ERROR("  %s", msg.strs[i].name.c_str());
        // @todo Check that there are no duplicates. Make this error more
        // explicit.
        return false;
      }
      return true;
    }

    // This version of __toMessage__ is used during initialization of
    // statics when __getParamDescriptions__ can't be called yet.
    void __toMessage__(dynamic_reconfigure::Config &msg, const std::vector<AbstractParamDescriptionConstPtr> &__param_descriptions__, const std::vector<AbstractGroupDescriptionConstPtr> &__group_descriptions__) const
    {
      dynamic_reconfigure::ConfigTools::clear(msg);
      for (std::vector<AbstractParamDescriptionConstPtr>::const_iterator i = __param_descriptions__.begin(); i != __param_descriptions__.end(); ++i)
        (*i)->toMessage(msg, *this);

      for (std::vector<AbstractGroupDescriptionConstPtr>::const_iterator i = __group_descriptions__.begin(); i != __group_descriptions__.end(); ++i)
      {
        if((*i)->id == 0)
        {
          (*i)->toMessage(msg, *this);
        }
      }
    }

    void __toMessage__(dynamic_reconfigure::Config &msg) const
    {
      const std::vector<AbstractParamDescriptionConstPtr> &__param_descriptions__ = __getParamDescriptions__();
      const std::vector<AbstractGroupDescriptionConstPtr> &__group_descriptions__ = __getGroupDescriptions__();
      __toMessage__(msg, __param_descriptions__, __group_descriptions__);
    }

    void __toServer__(const ros::NodeHandle &nh) const
    {
      const std::vector<AbstractParamDescriptionConstPtr> &__param_descriptions__ = __getParamDescriptions__();
      for (std::vector<AbstractParamDescriptionConstPtr>::const_iterator i = __param_descriptions__.begin(); i != __param_descriptions__.end(); ++i)
        (*i)->toServer(nh, *this);
    }

    void __fromServer__(const ros::NodeHandle &nh)
    {
      static bool setup=false;

      const std::vector<AbstractParamDescriptionConstPtr> &__param_descriptions__ = __getParamDescriptions__();
      for (std::vector<AbstractParamDescriptionConstPtr>::const_iterator i = __param_descriptions__.begin(); i != __param_descriptions__.end(); ++i)
        (*i)->fromServer(nh, *this);

      const std::vector<AbstractGroupDescriptionConstPtr> &__group_descriptions__ = __getGroupDescriptions__();
      for (std::vector<AbstractGroupDescriptionConstPtr>::const_iterator i = __group_descriptions__.begin(); i != __group_descriptions__.end(); i++){
        if (!setup && (*i)->id == 0) {
          setup = true;
          boost::any n = boost::any(this);
          (*i)->setInitialState(n);
        }
      }
    }

    void __clamp__()
    {
      const std::vector<AbstractParamDescriptionConstPtr> &__param_descriptions__ = __getParamDescriptions__();
      const CropDecimateConfig &__max__ = __getMax__();
      const CropDecimateConfig &__min__ = __getMin__();
      for (std::vector<AbstractParamDescriptionConstPtr>::const_iterator i = __param_descriptions__.begin(); i != __param_descriptions__.end(); ++i)
        (*i)->clamp(*this, __max__, __min__);
    }

    uint32_t __level__(const CropDecimateConfig &config) const
    {
      const std::vector<AbstractParamDescriptionConstPtr> &__param_descriptions__ = __getParamDescriptions__();
      uint32_t level = 0;
      for (std::vector<AbstractParamDescriptionConstPtr>::const_iterator i = __param_descriptions__.begin(); i != __param_descriptions__.end(); ++i)
        (*i)->calcLevel(level, config, *this);
      return level;
    }

    static const dynamic_reconfigure::ConfigDescription &__getDescriptionMessage__();
    static const CropDecimateConfig &__getDefault__();
    static const CropDecimateConfig &__getMax__();
    static const CropDecimateConfig &__getMin__();
    static const std::vector<AbstractParamDescriptionConstPtr> &__getParamDescriptions__();
    static const std::vector<AbstractGroupDescriptionConstPtr> &__getGroupDescriptions__();

  private:
    static const CropDecimateConfigStatics *__get_statics__();
  };

  template <> // Max and min are ignored for strings.
  inline void CropDecimateConfig::ParamDescription<std::string>::clamp(CropDecimateConfig &config, const CropDecimateConfig &max, const CropDecimateConfig &min) const
  {
    (void) config;
    (void) min;
    (void) max;
    return;
  }

  class CropDecimateConfigStatics
  {
    friend class CropDecimateConfig;

    CropDecimateConfigStatics()
    {
CropDecimateConfig::GroupDescription<CropDecimateConfig::DEFAULT, CropDecimateConfig> Default("Default", "", 0, 0, true, &CropDecimateConfig::groups);
//#line 291 "/opt/ros/noetic/lib/python3/dist-packages/dynamic_reconfigure/parameter_generator_catkin.py"
      __min__.decimation_x = 1;
//#line 291 "/opt/ros/noetic/lib/python3/dist-packages/dynamic_reconfigure/parameter_generator_catkin.py"
      __max__.decimation_x = 16;
//#line 291 "/opt/ros/noetic/lib/python3/dist-packages/dynamic_reconfigure/parameter_generator_catkin.py"
      __default__.decimation_x = 1;
//#line 291 "/opt/ros/noetic/lib/python3/dist-packages/dynamic_reconfigure/parameter_generator_catkin.py"
      Default.abstract_parameters.push_back(CropDecimateConfig::AbstractParamDescriptionConstPtr(new CropDecimateConfig::ParamDescription<int>("decimation_x", "int", 0, "Number of pixels to decimate to one horizontally", "", &CropDecimateConfig::decimation_x)));
//#line 291 "/opt/ros/noetic/lib/python3/dist-packages/dynamic_reconfigure/parameter_generator_catkin.py"
      __param_descriptions__.push_back(CropDecimateConfig::AbstractParamDescriptionConstPtr(new CropDecimateConfig::ParamDescription<int>("decimation_x", "int", 0, "Number of pixels to decimate to one horizontally", "", &CropDecimateConfig::decimation_x)));
//#line 291 "/opt/ros/noetic/lib/python3/dist-packages/dynamic_reconfigure/parameter_generator_catkin.py"
      __min__.decimation_y = 1;
//#line 291 "/opt/ros/noetic/lib/python3/dist-packages/dynamic_reconfigure/parameter_generator_catkin.py"
      __max__.decimation_y = 16;
//#line 291 "/opt/ros/noetic/lib/python3/dist-packages/dynamic_reconfigure/parameter_generator_catkin.py"
      __default__.decimation_y = 1;
//#line 291 "/opt/ros/noetic/lib/python3/dist-packages/dynamic_reconfigure/parameter_generator_catkin.py"
      Default.abstract_parameters.push_back(CropDecimateConfig::AbstractParamDescriptionConstPtr(new CropDecimateConfig::ParamDescription<int>("decimation_y", "int", 0, "Number of pixels to decimate to one vertically", "", &CropDecimateConfig::decimation_y)));
//#line 291 "/opt/ros/noetic/lib/python3/dist-packages/dynamic_reconfigure/parameter_generator_catkin.py"
      __param_descriptions__.push_back(CropDecimateConfig::AbstractParamDescriptionConstPtr(new CropDecimateConfig::ParamDescription<int>("decimation_y", "int", 0, "Number of pixels to decimate to one vertically", "", &CropDecimateConfig::decimation_y)));
//#line 291 "/opt/ros/noetic/lib/python3/dist-packages/dynamic_reconfigure/parameter_generator_catkin.py"
      __min__.x_offset = 0;
//#line 291 "/opt/ros/noetic/lib/python3/dist-packages/dynamic_reconfigure/parameter_generator_catkin.py"
      __max__.x_offset = 2447;
//#line 291 "/opt/ros/noetic/lib/python3/dist-packages/dynamic_reconfigure/parameter_generator_catkin.py"
      __default__.x_offset = 0;
//#line 291 "/opt/ros/noetic/lib/python3/dist-packages/dynamic_reconfigure/parameter_generator_catkin.py"
      Default.abstract_parameters.push_back(CropDecimateConfig::AbstractParamDescriptionConstPtr(new CropDecimateConfig::ParamDescription<int>("x_offset", "int", 0, "X offset of the region of interest", "", &CropDecimateConfig::x_offset)));
//#line 291 "/opt/ros/noetic/lib/python3/dist-packages/dynamic_reconfigure/parameter_generator_catkin.py"
      __param_descriptions__.push_back(CropDecimateConfig::AbstractParamDescriptionConstPtr(new CropDecimateConfig::ParamDescription<int>("x_offset", "int", 0, "X offset of the region of interest", "", &CropDecimateConfig::x_offset)));
//#line 291 "/opt/ros/noetic/lib/python3/dist-packages/dynamic_reconfigure/parameter_generator_catkin.py"
      __min__.y_offset = 0;
//#line 291 "/opt/ros/noetic/lib/python3/dist-packages/dynamic_reconfigure/parameter_generator_catkin.py"
      __max__.y_offset = 2049;
//#line 291 "/opt/ros/noetic/lib/python3/dist-packages/dynamic_reconfigure/parameter_generator_catkin.py"
      __default__.y_offset = 0;
//#line 291 "/opt/ros/noetic/lib/python3/dist-packages/dynamic_reconfigure/parameter_generator_catkin.py"
      Default.abstract_parameters.push_back(CropDecimateConfig::AbstractParamDescriptionConstPtr(new CropDecimateConfig::ParamDescription<int>("y_offset", "int", 0, "Y offset of the region of interest", "", &CropDecimateConfig::y_offset)));
//#line 291 "/opt/ros/noetic/lib/python3/dist-packages/dynamic_reconfigure/parameter_generator_catkin.py"
      __param_descriptions__.push_back(CropDecimateConfig::AbstractParamDescriptionConstPtr(new CropDecimateConfig::ParamDescription<int>("y_offset", "int", 0, "Y offset of the region of interest", "", &CropDecimateConfig::y_offset)));
//#line 291 "/opt/ros/noetic/lib/python3/dist-packages/dynamic_reconfigure/parameter_generator_catkin.py"
      __min__.width = 0;
//#line 291 "/opt/ros/noetic/lib/python3/dist-packages/dynamic_reconfigure/parameter_generator_catkin.py"
      __max__.width = 2448;
//#line 291 "/opt/ros/noetic/lib/python3/dist-packages/dynamic_reconfigure/parameter_generator_catkin.py"
      __default__.width = 0;
//#line 291 "/opt/ros/noetic/lib/python3/dist-packages/dynamic_reconfigure/parameter_generator_catkin.py"
      Default.abstract_parameters.push_back(CropDecimateConfig::AbstractParamDescriptionConstPtr(new CropDecimateConfig::ParamDescription<int>("width", "int", 0, "Width of the region of interest", "", &CropDecimateConfig::width)));
//#line 291 "/opt/ros/noetic/lib/python3/dist-packages/dynamic_reconfigure/parameter_generator_catkin.py"
      __param_descriptions__.push_back(CropDecimateConfig::AbstractParamDescriptionConstPtr(new CropDecimateConfig::ParamDescription<int>("width", "int", 0, "Width of the region of interest", "", &CropDecimateConfig::width)));
//#line 291 "/opt/ros/noetic/lib/python3/dist-packages/dynamic_reconfigure/parameter_generator_catkin.py"
      __min__.height = 0;
//#line 291 "/opt/ros/noetic/lib/python3/dist-packages/dynamic_reconfigure/parameter_generator_catkin.py"
      __max__.height = 2050;
//#line 291 "/opt/ros/noetic/lib/python3/dist-packages/dynamic_reconfigure/parameter_generator_catkin.py"
      __default__.height = 0;
//#line 291 "/opt/ros/noetic/lib/python3/dist-packages/dynamic_reconfigure/parameter_generator_catkin.py"
      Default.abstract_parameters.push_back(CropDecimateConfig::AbstractParamDescriptionConstPtr(new CropDecimateConfig::ParamDescription<int>("height", "int", 0, "Height of the region of interest", "", &CropDecimateConfig::height)));
//#line 291 "/opt/ros/noetic/lib/python3/dist-packages/dynamic_reconfigure/parameter_generator_catkin.py"
      __param_descriptions__.push_back(CropDecimateConfig::AbstractParamDescriptionConstPtr(new CropDecimateConfig::ParamDescription<int>("height", "int", 0, "Height of the region of interest", "", &CropDecimateConfig::height)));
//#line 291 "/opt/ros/noetic/lib/python3/dist-packages/dynamic_reconfigure/parameter_generator_catkin.py"
      __min__.interpolation = 0;
//#line 291 "/opt/ros/noetic/lib/python3/dist-packages/dynamic_reconfigure/parameter_generator_catkin.py"
      __max__.interpolation = 4;
//#line 291 "/opt/ros/noetic/lib/python3/dist-packages/dynamic_reconfigure/parameter_generator_catkin.py"
      __default__.interpolation = 0;
//#line 291 "/opt/ros/noetic/lib/python3/dist-packages/dynamic_reconfigure/parameter_generator_catkin.py"
      Default.abstract_parameters.push_back(CropDecimateConfig::AbstractParamDescriptionConstPtr(new CropDecimateConfig::ParamDescription<int>("interpolation", "int", 0, "Sampling algorithm", "{'enum': [{'name': 'NN', 'type': 'int', 'value': 0, 'srcline': 21, 'srcfile': '/home/realsense-ws/src/image_pipeline/image_proc/cfg/CropDecimate.cfg', 'description': 'Nearest-neighbor sampling', 'ctype': 'int', 'cconsttype': 'const int'}, {'name': 'Linear', 'type': 'int', 'value': 1, 'srcline': 22, 'srcfile': '/home/realsense-ws/src/image_pipeline/image_proc/cfg/CropDecimate.cfg', 'description': 'Bilinear interpolation', 'ctype': 'int', 'cconsttype': 'const int'}, {'name': 'Cubic', 'type': 'int', 'value': 2, 'srcline': 23, 'srcfile': '/home/realsense-ws/src/image_pipeline/image_proc/cfg/CropDecimate.cfg', 'description': 'Bicubic interpolation over 4x4 neighborhood', 'ctype': 'int', 'cconsttype': 'const int'}, {'name': 'Area', 'type': 'int', 'value': 3, 'srcline': 24, 'srcfile': '/home/realsense-ws/src/image_pipeline/image_proc/cfg/CropDecimate.cfg', 'description': 'Resampling using pixel area relation', 'ctype': 'int', 'cconsttype': 'const int'}, {'name': 'Lanczos4', 'type': 'int', 'value': 4, 'srcline': 25, 'srcfile': '/home/realsense-ws/src/image_pipeline/image_proc/cfg/CropDecimate.cfg', 'description': 'Lanczos interpolation over 8x8 neighborhood', 'ctype': 'int', 'cconsttype': 'const int'}], 'enum_description': 'interpolation type'}", &CropDecimateConfig::interpolation)));
//#line 291 "/opt/ros/noetic/lib/python3/dist-packages/dynamic_reconfigure/parameter_generator_catkin.py"
      __param_descriptions__.push_back(CropDecimateConfig::AbstractParamDescriptionConstPtr(new CropDecimateConfig::ParamDescription<int>("interpolation", "int", 0, "Sampling algorithm", "{'enum': [{'name': 'NN', 'type': 'int', 'value': 0, 'srcline': 21, 'srcfile': '/home/realsense-ws/src/image_pipeline/image_proc/cfg/CropDecimate.cfg', 'description': 'Nearest-neighbor sampling', 'ctype': 'int', 'cconsttype': 'const int'}, {'name': 'Linear', 'type': 'int', 'value': 1, 'srcline': 22, 'srcfile': '/home/realsense-ws/src/image_pipeline/image_proc/cfg/CropDecimate.cfg', 'description': 'Bilinear interpolation', 'ctype': 'int', 'cconsttype': 'const int'}, {'name': 'Cubic', 'type': 'int', 'value': 2, 'srcline': 23, 'srcfile': '/home/realsense-ws/src/image_pipeline/image_proc/cfg/CropDecimate.cfg', 'description': 'Bicubic interpolation over 4x4 neighborhood', 'ctype': 'int', 'cconsttype': 'const int'}, {'name': 'Area', 'type': 'int', 'value': 3, 'srcline': 24, 'srcfile': '/home/realsense-ws/src/image_pipeline/image_proc/cfg/CropDecimate.cfg', 'description': 'Resampling using pixel area relation', 'ctype': 'int', 'cconsttype': 'const int'}, {'name': 'Lanczos4', 'type': 'int', 'value': 4, 'srcline': 25, 'srcfile': '/home/realsense-ws/src/image_pipeline/image_proc/cfg/CropDecimate.cfg', 'description': 'Lanczos interpolation over 8x8 neighborhood', 'ctype': 'int', 'cconsttype': 'const int'}], 'enum_description': 'interpolation type'}", &CropDecimateConfig::interpolation)));
//#line 246 "/opt/ros/noetic/lib/python3/dist-packages/dynamic_reconfigure/parameter_generator_catkin.py"
      Default.convertParams();
//#line 246 "/opt/ros/noetic/lib/python3/dist-packages/dynamic_reconfigure/parameter_generator_catkin.py"
      __group_descriptions__.push_back(CropDecimateConfig::AbstractGroupDescriptionConstPtr(new CropDecimateConfig::GroupDescription<CropDecimateConfig::DEFAULT, CropDecimateConfig>(Default)));
//#line 369 "/opt/ros/noetic/share/dynamic_reconfigure/cmake/../templates/ConfigType.h.template"

      for (std::vector<CropDecimateConfig::AbstractGroupDescriptionConstPtr>::const_iterator i = __group_descriptions__.begin(); i != __group_descriptions__.end(); ++i)
      {
        __description_message__.groups.push_back(**i);
      }
      __max__.__toMessage__(__description_message__.max, __param_descriptions__, __group_descriptions__);
      __min__.__toMessage__(__description_message__.min, __param_descriptions__, __group_descriptions__);
      __default__.__toMessage__(__description_message__.dflt, __param_descriptions__, __group_descriptions__);
    }
    std::vector<CropDecimateConfig::AbstractParamDescriptionConstPtr> __param_descriptions__;
    std::vector<CropDecimateConfig::AbstractGroupDescriptionConstPtr> __group_descriptions__;
    CropDecimateConfig __max__;
    CropDecimateConfig __min__;
    CropDecimateConfig __default__;
    dynamic_reconfigure::ConfigDescription __description_message__;

    static const CropDecimateConfigStatics *get_instance()
    {
      // Split this off in a separate function because I know that
      // instance will get initialized the first time get_instance is
      // called, and I am guaranteeing that get_instance gets called at
      // most once.
      static CropDecimateConfigStatics instance;
      return &instance;
    }
  };

  inline const dynamic_reconfigure::ConfigDescription &CropDecimateConfig::__getDescriptionMessage__()
  {
    return __get_statics__()->__description_message__;
  }

  inline const CropDecimateConfig &CropDecimateConfig::__getDefault__()
  {
    return __get_statics__()->__default__;
  }

  inline const CropDecimateConfig &CropDecimateConfig::__getMax__()
  {
    return __get_statics__()->__max__;
  }

  inline const CropDecimateConfig &CropDecimateConfig::__getMin__()
  {
    return __get_statics__()->__min__;
  }

  inline const std::vector<CropDecimateConfig::AbstractParamDescriptionConstPtr> &CropDecimateConfig::__getParamDescriptions__()
  {
    return __get_statics__()->__param_descriptions__;
  }

  inline const std::vector<CropDecimateConfig::AbstractGroupDescriptionConstPtr> &CropDecimateConfig::__getGroupDescriptions__()
  {
    return __get_statics__()->__group_descriptions__;
  }

  inline const CropDecimateConfigStatics *CropDecimateConfig::__get_statics__()
  {
    const static CropDecimateConfigStatics *statics;

    if (statics) // Common case
      return statics;

    boost::mutex::scoped_lock lock(dynamic_reconfigure::__init_mutex__);

    if (statics) // In case we lost a race.
      return statics;

    statics = CropDecimateConfigStatics::get_instance();

    return statics;
  }

//#line 21 "/home/realsense-ws/src/image_pipeline/image_proc/cfg/CropDecimate.cfg"
      const int CropDecimate_NN = 0;
//#line 22 "/home/realsense-ws/src/image_pipeline/image_proc/cfg/CropDecimate.cfg"
      const int CropDecimate_Linear = 1;
//#line 23 "/home/realsense-ws/src/image_pipeline/image_proc/cfg/CropDecimate.cfg"
      const int CropDecimate_Cubic = 2;
//#line 24 "/home/realsense-ws/src/image_pipeline/image_proc/cfg/CropDecimate.cfg"
      const int CropDecimate_Area = 3;
//#line 25 "/home/realsense-ws/src/image_pipeline/image_proc/cfg/CropDecimate.cfg"
      const int CropDecimate_Lanczos4 = 4;
}

#undef DYNAMIC_RECONFIGURE_FINAL

#endif // __CROPDECIMATERECONFIGURATOR_H__
