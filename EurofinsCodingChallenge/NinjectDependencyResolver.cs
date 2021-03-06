﻿using Ninject;
using Services.Numbers;
using System;
using System.Collections.Generic;
using System.Web.Mvc;

namespace EurofinsCodingChallenge
{
    public class NinjectDependencyResolver : IDependencyResolver
    {
        private IKernel kernel;

        public NinjectDependencyResolver()
        {
            kernel = new StandardKernel();
            AddBindings();
        }

        public object GetService(Type serviceType)
        {
            return kernel.TryGet(serviceType);
        }

        public IEnumerable<object> GetServices(Type serviceType)
        {
            return kernel.GetAll(serviceType);
        }

        private void AddBindings()
        {
            kernel.Bind<INumbersService>().To<NumbersService>();
        }
    }
}