# $NetBSD: Makefile,v 1.4 2013/05/31 12:42:21 wiz Exp $
#

DISTNAME=	XML-SAX-ExpatXS-1.31
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	2
SVR4_PKGNAME=	p5xsx
CATEGORIES=	textproc perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=XML/}

MAINTAINER=	tnozaki@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/XML-SAX-ExpatXS/
COMMENT=	Perl SAX 2 XS extension to Expat parser
LICENSE=	${PERL5_LICENSE}

DEPENDS+=	p5-XML-SAX>=0.13:../../textproc/p5-XML-SAX

PKG_INSTALLATION_TYPES=	overwrite pkgviews

PERL5_PACKLIST=		auto/XML/SAX/ExpatXS/.packlist
MAKE_PARAMS+=		EXPATLIBPATH=${BUILDLINK_PREFIX.expat}/lib
MAKE_PARAMS+=		EXPATINCPATH=${BUILDLINK_PREFIX.expat}/include

FILES_SUBST+=	PERL5_INSTALLVENDORLIB=${PERL5_INSTALLVENDORLIB:Q}

.include "../../lang/perl5/module.mk"
.include "../../textproc/expat/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
