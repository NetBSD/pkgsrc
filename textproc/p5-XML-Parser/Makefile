# $NetBSD: Makefile,v 1.9 2001/10/16 00:03:50 hubertf Exp $
#

DISTNAME=	XML-Parser.2.30
PKGNAME=	p5-${DISTNAME:S/./-/1}
WRKSRC=		${WRKDIR}/${DISTNAME:S/./-/1}
CATEGORIES=	textproc perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=XML/}

MAINTAINER=	bad@netbsd.org
HOMEPAGE=	http://wwwx.netheaven.com/~coopercc/xmlparser/intro.html
COMMENT=	Perl extension interface to James Clark's XML parser, expat

USE_PERL5=	# defined
PERL5_PACKLIST=	${PERL5_SITEARCH}/auto/XML/Parser/.packlist

do-configure:
	@cd ${WRKSRC}; ${SETENV} ${MAKE_ENV} ${PERL5} Makefile.PL \
		EXPATLIBPATH=${LOCALBASE}/lib \
		EXPATINCPATH=${LOCALBASE}/include

.include "../../textproc/expat/buildlink.mk"
.include "../../mk/bsd.pkg.mk"
