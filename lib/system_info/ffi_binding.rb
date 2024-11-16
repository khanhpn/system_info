require 'ffi'

module SystemInfo
  extend FFI::Library

  ffi_lib File.expand_path('../../ext/system_info/system_info.bundle', __dir__)

  attach_function :get_system_info, [], :string

  def self.info
    get_system_info
  end
end
