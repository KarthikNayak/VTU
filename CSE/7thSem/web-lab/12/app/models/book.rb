class Book < ActiveRecord::Base
  attr_accessible :ano, :author, :edition, :publisher, :title
end
