# $NetBSD: Makefile,v 1.14 2002/08/20 14:57:45 wiz Exp $
#

DISTNAME=	XML-Parser-2.31
PKGNAME=	p5-${DISTNAME}
SVR4_PKGNAME=	p5xpa
CATEGORIES=	textproc perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=XML/}

MAINTAINER=	bad@netbsd.org
#HOMEPAGE=	http://wwwx.netheaven.com/~coopercc/xmlparser/intro.html
COMMENT=	Perl extension interface to James Clark's XML parser, expat

USE_BUILDLINK_ONLY=	YES
PERL5_PACKLIST=		${PERL5_SITEARCH}/auto/XML/Parser/.packlist

do-configure:
	@cd ${WRKSRC}; ${SETENV} ${MAKE_ENV} ${PERL5} Makefile.PL

.include "../../lang/perl5/buildlink.mk"
.include "../../textproc/expat/buildlink.mk"
.include "../../mk/bsd.pkg.mk"
