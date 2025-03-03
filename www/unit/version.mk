# $NetBSD: version.mk,v 1.16 2025/03/03 19:58:25 osa Exp $
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
UNIT_VERSION=	1.34.2

# Define NGINX Unit's modules directory
UNIT_EXTENSION_DIR=	libexec/unit/modules

.endif	# UNITVERSION_MK
