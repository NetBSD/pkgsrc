# $NetBSD: Makefile,v 1.12 2017/06/05 14:24:58 ryoon Exp $

DISTNAME=	XML-SAX-ExpatXS-1.33
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	4
CATEGORIES=	textproc perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=XML/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/XML-SAX-ExpatXS/
COMMENT=	Perl SAX 2 XS extension to Expat parser
LICENSE=	${PERL5_LICENSE}

DEPENDS+=	p5-XML-SAX>=0.13:../../textproc/p5-XML-SAX

PERL5_PACKLIST=		auto/XML/SAX/ExpatXS/.packlist
MAKE_PARAMS+=		EXPATLIBPATH=${BUILDLINK_PREFIX.expat}/lib
MAKE_PARAMS+=		EXPATINCPATH=${BUILDLINK_PREFIX.expat}/include

FILES_SUBST+=	PERL5_INSTALLVENDORLIB=${PERL5_INSTALLVENDORLIB:Q}

.include "../../lang/perl5/module.mk"
.include "../../textproc/expat/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
