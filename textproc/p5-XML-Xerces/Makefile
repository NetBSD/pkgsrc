# $NetBSD: Makefile,v 1.20 2006/08/10 13:48:23 abs Exp $
#

DISTNAME=	XML-Xerces-2.7.0-0
PKGNAME=	p5-${DISTNAME:C/-([0-9]*)$/.\1/}
CATEGORIES=	textproc perl5
MASTER_SITES=	${MASTER_SITE_APACHE:=xml/xerces-p/}

MAINTAINER=	manu@NetBSD.org
HOMEPAGE=	http://xml.apache.org/xerces-p/
COMMENT=	Validating XML parser API for Perl

CONFLICTS+=	XML-Xerces-[0-9]*

PKG_INSTALLATION_TYPES=	overwrite pkgviews

USE_LANGUAGES=	c c++
CC=c++
USE_TOOLS+=	gmake
PERL5_PACKLIST=	auto/XML/Xerces/.packlist

MAKE_ENV+=	XERCESCROOT="${BUILDLINK_PREFIX.xerces-c}" LANG=""

# Xerces-C is built unthreaded in pkgsrc (for now).
BUILDLINK_TRANSFORM+=	rm:-lpthread

BUILDLINK_API_DEPENDS.xerces-c+=	xerces-c>=2.7.0
.include "../../textproc/xerces-c/buildlink3.mk"

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
