# $NetBSD: Makefile,v 1.44 2021/05/24 19:55:34 wiz Exp $

DISTNAME=		HTML-Template-2.97
PKGNAME=		p5-${DISTNAME}
PKGREVISION=		5
CATEGORIES=		www perl5
MASTER_SITES=		${MASTER_SITE_PERL_CPAN:=HTML/}
MASTER_SITES+=		${MASTER_SITE_SOURCEFORGE:=html-template/}

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://html-template.sourceforge.net/
COMMENT=		Perl5 module to create HTML templates with simple tags
LICENSE=		${PERL5_LICENSE}

DEPENDS+=		p5-CGI-[0-9]*:../../www/p5-CGI

PERL5_PACKLIST=		auto/HTML/Template/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
