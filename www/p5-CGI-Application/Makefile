# $NetBSD: Makefile,v 1.2 2001/02/17 17:22:20 wiz Exp $

DISTNAME=		CGI-Application-1.2
PKGNAME=		p5-${DISTNAME}
CATEGORIES=		www perl5
MASTER_SITES=		${MASTER_SITE_PERL_CPAN:=CGI/}

MAINTAINER=		jlam@netbsd.org
COMMENT=		perl5 module to create sophisticated, reusable web-based applications

DEPENDS+=		p5-CGI-[0-9]*:../../www/p5-CGI
DEPENDS+=		p5-HTML-Template-*:../../www/p5-HTML-Template

USE_PERL5=		# defined
PERL5_PACKLIST=		${PERL5_SITEARCH}/auto/CGI/Application/.packlist

do-configure:
	@cd ${WRKSRC}; ${SETENV} ${MAKE_ENV} ${PERL5} Makefile.PL

.include "../../mk/bsd.pkg.mk"
