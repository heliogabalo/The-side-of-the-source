#!/bin/bash
#
ttl=600
#
cut=/usr/bin/cut
getent=/usr/bin/getent
rpc_pipefs=/var/lib/nfs/rpc_pipefs
#
die()
{
	echo "Usage: $0 cache_name entry_name"
	exit 1
}

[ $# -lt 2 ] && die
cachename="$1"
cache_path=${rpc_pipefs}/cache/${cachename}/channel

case "${cachename}" in
	dns_resolve)
		name="$2"
		result="$(${getent} hosts ${name} | ${cut} -f1 -d\ )"
		[ -z "${result}" ] && result="0"
		;;
	*)
		die
		;;
esac
echo "${result} ${name} ${ttl}" >${cache_path}
