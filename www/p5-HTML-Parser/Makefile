# $NetBSD: Makefile,v 1.14 2001/10/18 15:20:49 veego Exp $
#

DISTNAME=		HTML-Parser-3.25
PKGNAME=		p5-${DISTNAME}
SVR4_PKGNAME=		p5hpa
CATEGORIES=		www perl5
MASTER_SITES=		${MASTER_SITE_PERL_CPAN:=HTML/}

MAINTAINER=		jlam@netbsd.org
COMMENT=		perl5 module to parse HTML text documents

DEPENDS+=		p5-HTML-Tagset>=3.0:../../www/p5-HTML-Tagset

USE_PERL5=		# defined
PERL5_PACKLIST=		${PERL5_SITEARCH}/auto/HTML/Parser/.packlist

do-configure:
	@cd ${WRKSRC}; ${SETENV} ${MAKE_ENV} ${PERL5} Makefile.PL

.include "../../mk/bsd.pkg.mk"
