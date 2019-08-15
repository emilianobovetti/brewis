<?php

use App\User;
use Illuminate\Database\Seeder;
use Illuminate\Support\Facades\Hash;
use Illuminate\Database\Eloquent\Model;

class DatabaseSeeder extends Seeder {

    public function run()
    {
        Model::unguard();

        $this->call('AdminSeeder');
    }
}

class AdminSeeder extends Seeder {

    public function run()
    {
        if (User::count() === 0)
        {
            $user = new User;
            $user->name = 'admin';
            $user->hashPassword('admin');
            $user->save();

            $this->command->info('User `admin` inserted');
        }
        else
        {
            $this->command->info('User table not empty');
        }
    }
}
