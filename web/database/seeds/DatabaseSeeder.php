<?php

use App\User;
use Illuminate\Database\Seeder;
use Illuminate\Support\Facades\Hash;
use Illuminate\Database\Eloquent\Model;

class DatabaseSeeder extends Seeder {

    public function run()
    {
        Model::unguard();

        $this->call('UsersTableSeeder');
        $this->command->info('Users table seeded');
    }
}

class UsersTableSeeder extends Seeder {

    public function run()
    {
        $user = new User;
        $user->name = 'admin';
        $user->hashPassword('admin');
        $user->save();
    }
}
