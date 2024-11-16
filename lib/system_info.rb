require "system_info/version"

module SystemInfo
  class Error < StandardError; end
  def self.info
    get_system_info
  end
end
