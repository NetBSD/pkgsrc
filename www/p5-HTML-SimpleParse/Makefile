# $NetBSD: Makefile,v 1.2 2001/10/18 15:20:50 veego Exp $

DISTNAME=	HTML-SimpleParse-0.10
PKGNAME=	p5-${DISTNAME}
SVR4_PKGNAME=	p5hsp
CATEGORIES=	www perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=HTML/}

MAINTAINER=	packages@netbsd.org
COMMENT=	perl5 module implementing a bare-bones HTML parser

USE_PERL5=	YES
PERL5_PACKLIST=	${PERL5_SITEARCH}/auto/HTML/SimpleParse/.packlist

do-configure:
	@cd ${WRKSRC}; ${SETENV} ${MAKE_ENV} ${PERL5} Makefile.PL

.include "../../mk/bsd.pkg.mk"
