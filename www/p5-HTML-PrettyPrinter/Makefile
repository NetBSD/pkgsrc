# $NetBSD: Makefile,v 1.2 2001/02/17 17:22:23 wiz Exp $

DISTNAME=		HTML-PrettyPrinter-0.03
PKGNAME=		p5-${DISTNAME}
CATEGORIES=		www perl5
MASTER_SITES=		${MASTER_SITE_PERL_CPAN:=HTML/}

MAINTAINER=		jlam@netbsd.org
COMMENT=		perl5 module for pretty-printing HTML

DEPENDS+=		p5-HTML-Tree>=3.0:../../www/p5-HTML-Tree
DEPENDS+=		p5-HTML-Tagset-*:../../www/p5-HTML-Tagset

USE_PERL5=		# defined
PERL5_PACKLIST=		${PERL5_SITEARCH}/auto/HTML/PrettyPrinter/.packlist

do-configure:
	@cd ${WRKSRC}; ${SETENV} ${MAKE_ENV} ${PERL5} Makefile.PL

.include "../../mk/bsd.pkg.mk"
