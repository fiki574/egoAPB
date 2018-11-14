using System;

namespace APBClient.Networking
{
    [AttributeUsage(AttributeTargets.Class)]
    internal class PacketHandlerAttribute : Attribute
    {
        public readonly APBOpCode OpCode;

        public PacketHandlerAttribute(APBOpCode opCode)
        {
            OpCode = opCode;
        }
    }
}