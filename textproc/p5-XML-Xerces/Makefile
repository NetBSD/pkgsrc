# $NetBSD: Makefile,v 1.1.1.1 2003/06/23 08:46:06 jlam Exp $
#

DISTNAME=	XML-Xerces-1.7.0-3
PKGNAME=	p5-${DISTNAME:C/-([0-9]*)$/.\1/}
CATEGORIES=	textproc
MASTER_SITES=	http://xml.apache.org/dist/xerces-p/stable/archives/

MAINTAINER=	manu@netbsd.org
HOMEPAGE=	http://xml.apache.org/xerces-p/
COMMENT=	Validating XML parser API for Perl

CONFLICTS+=	XML-Xerces-[0-9]*

USE_BUILDLINK2=	YES
USE_GMAKE=	YES
PERL5_REQD=	5.6.0
PERL5_PACKLIST=	${PERL5_SITEARCH}/auto/XML/Xerces/.packlist

MAKE_ENV+=	XERCESCROOT="${BUILDLINK_PREFIX.xerces-c}"
MAKE_ENV+=	ICUROOT="${BUILDLINK_PREFIX.icu}"

# Xerces-C is built unthreaded in pkgsrc (for now).
BUILDLINK_TRANSFORM+=	s:-lpthread:

.include "../../lang/perl5/module.mk"
.include "../../textproc/xerces-c/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
