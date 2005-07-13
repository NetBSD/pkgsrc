# $NetBSD: Makefile,v 1.24 2005/07/13 18:01:43 jlam Exp $
#

DISTNAME=	XML-Parser-2.34
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	2
SVR4_PKGNAME=	p5xpa
CATEGORIES=	textproc perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=XML/}

MAINTAINER=	bad@NetBSD.org
#HOMEPAGE=	http://wwwx.netheaven.com/~coopercc/xmlparser/intro.html
COMMENT=	Perl extension interface to James Clark's XML parser, expat

PKG_INSTALLATION_TYPES=	overwrite pkgviews

PERL5_PACKLIST=		auto/XML/Parser/.packlist
MAKE_PARAMS+=		EXPATLIBPATH=${BUILDLINK_PREFIX.expat}/lib
MAKE_PARAMS+=		EXPATINCPATH=${BUILDLINK_PREFIX.expat}/include

.include "../../lang/perl5/module.mk"
.include "../../textproc/expat/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
