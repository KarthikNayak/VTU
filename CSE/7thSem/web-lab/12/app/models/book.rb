class Book < ActiveRecord::Base
  attr_accessible :access_no, :author, :edition, :publisher, :title
end
