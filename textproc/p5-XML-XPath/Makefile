# $NetBSD: Makefile,v 1.4 2001/10/18 15:20:45 veego Exp $

DISTNAME=	XML-XPath-1.08
PKGNAME=	p5-${DISTNAME}
SVR4_PKGNAME=	p5xxp
CATEGORIES=	textproc perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=XML/}

MAINTAINER=	packages@NetBSD.org
HOMEPAGE=	http://sergeant.org
COMMENT=	XML XPath software

USE_PERL5=	# defined
PERL5_PACKLIST=	${PERL5_SITEARCH}/auto/XML/XPath/.packlist

do-configure:
	@cd ${WRKSRC}; ${SETENV} ${MAKE_ENV} ${PERL5} Makefile.PL

.include "../../mk/bsd.pkg.mk"
