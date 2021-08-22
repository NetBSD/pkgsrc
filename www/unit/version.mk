# $NetBSD: version.mk,v 1.2 2021/08/22 04:00:43 gutteridge Exp $
#
# UNIT_EXTENSION_DIR
#	Relative path to ${PREFIX} for NGINX Unit's modules.
#
#	Example: libexec/unit/modules
#
# Keywords: unit
#

.if !defined(UNITVERSION_MK)
UNITVERSION_MK=	defined

# Define NGINX Unit's version.
UNIT_VERSION=	1.25.0

# Define NGINX Unit's modules directory
UNIT_EXTENSION_DIR=	libexec/unit/modules

.endif	# UNITVERSION_MK
