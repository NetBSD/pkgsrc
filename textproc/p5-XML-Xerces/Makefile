# $NetBSD: Makefile,v 1.13 2005/08/06 06:19:35 jlam Exp $
#

DISTNAME=	XML-Xerces-2.3.0-4
PKGNAME=	p5-${DISTNAME:C/-([0-9]*)$/.\1/}
PKGREVISION=	3
CATEGORIES=	textproc perl5
MASTER_SITES=	http://www.apache.org/dist/xml/xerces-p/

MAINTAINER=	manu@NetBSD.org
HOMEPAGE=	http://xml.apache.org/xerces-p/
COMMENT=	Validating XML parser API for Perl

CONFLICTS+=	XML-Xerces-[0-9]*

PKG_INSTALLATION_TYPES=	overwrite pkgviews

USE_TOOLS+=	gmake
PERL5_PACKLIST=	auto/XML/Xerces/.packlist

MAKE_ENV+=	XERCESCROOT="${BUILDLINK_PREFIX.xerces-c}" LANG=""

# Xerces-C is built unthreaded in pkgsrc (for now).
BUILDLINK_TRANSFORM+=	rm:-lpthread

BUILDLINK_DEPENDS.xerces-c=     xerces-c>=2.3.0
.include "../../textproc/xerces-c/buildlink3.mk"

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
