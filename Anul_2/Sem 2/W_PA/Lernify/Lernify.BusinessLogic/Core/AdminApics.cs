﻿using System.Collections.Generic;
using System.Linq;
using AutoMapper;
using Lernify.BusinessLogic.DBModel;
using Lernify.Domain.Entities.User;
using Lernify.Domain.Enums;

namespace Lernify.BusinessLogic.Core
{
     public class AdminApics
     {
          internal List<UserMinimal> GetUsers()
          {
               List<UDbTable> users;
               var configure = new MapperConfiguration(cfg => cfg.CreateMap<UDbTable, UserMinimal>());
               IMapper mapper = configure.CreateMapper();

               using (var db = new UserContext())
               {
                    users = db.Users.ToList();
               }
               return mapper.Map<List<UserMinimal>>(users);
          }

          internal UserMinimal GetUserById(int id)
          {
               UDbTable user;
               using (var db = new UserContext())
                    user = db.Users.FirstOrDefault(u => u.Id == id);
               IMapper mapper = new MapperConfiguration(cfg => cfg.CreateMap<UDbTable, UserMinimal>()).CreateMapper();

               return user != null ? mapper.Map<UserMinimal>(user) : null;
          }
          internal void DeleteUser(int id)
          {
               UDbTable user;
               bool confDel = false;
               using (var db = new UserContext())
               {
                    user = db.Users.FirstOrDefault(p => p.Id == id);
                    if (user != null && user.Level != URole.Admin)
                    {
                         db.Users.Remove(user);
                         db.SaveChanges();
                         confDel = true;
                    }
               }

               if (confDel)
               {
                    using (var db = new SessionContext())
                    {
                         var session =
                              db.Sessions.FirstOrDefault(s => s.Username == user.Username || s.Username == user.Email);
                         if (session != null)
                         {
                              db.Sessions.Remove(session);
                              db.SaveChanges();
                         }
                    }
               }

          }
     }
}