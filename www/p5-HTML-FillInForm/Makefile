# $NetBSD: Makefile,v 1.2 2001/10/18 15:20:49 veego Exp $

DISTNAME=	HTML-FillInForm-0.19
PKGNAME=	p5-${DISTNAME}
SVR4_PKGNAME=	p5hfi
CATEGORIES=	www perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=HTML/}

MAINTAINER=	packages@netbsd.org
COMMENT=	perl5 module that populates HTML Forms with CGI data

DEPENDS+=	p5-HTML-Parser>=3.08:../../www/p5-HTML-Parser

USE_PERL5=	YES
PERL5_PACKLIST=	${PERL5_SITEARCH}/auto/HTML/FillInForm/.packlist

do-configure:
	@cd ${WRKSRC}; ${SETENV} ${MAKE_ENV} ${PERL5} Makefile.PL

.include "../../mk/bsd.pkg.mk"
