# $NetBSD: Makefile,v 1.4 2001/10/18 15:20:50 veego Exp $

DISTNAME=		HTML-Template-2.2
PKGNAME=		p5-${DISTNAME}
SVR4_PKGNAME=		p5htm
CATEGORIES=		www perl5
MASTER_SITES=		${MASTER_SITE_PERL_CPAN:=HTML/}

MAINTAINER=		jlam@netbsd.org
COMMENT=		perl5 module to create HTML templates by extending HTML with simple tags

USE_PERL5=		# defined
PERL5_PACKLIST=		${PERL5_SITEARCH}/auto/HTML/Template/.packlist

do-configure:
	@cd ${WRKSRC}; ${SETENV} ${MAKE_ENV} ${PERL5} Makefile.PL

.include "../../mk/bsd.pkg.mk"
