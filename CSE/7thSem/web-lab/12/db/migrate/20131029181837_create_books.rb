class CreateBooks < ActiveRecord::Migration
  def change
    create_table :books do |t|
      t.integer :access_no
      t.string :title
      t.string :author
      t.integer :edition
      t.string :publisher

      t.timestamps
    end
  end
end
