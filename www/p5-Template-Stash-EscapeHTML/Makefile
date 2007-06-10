# $NetBSD: Makefile,v 1.1.1.1 2007/06/10 23:24:05 abs Exp $

DISTNAME=	Template-Stash-EscapeHTML-0.01
PKGNAME=	p5-${DISTNAME}
CATEGORIES=	www perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=../../authors/id/I/IK/IKEBE/}

MAINTAINER=	abs@absd.org
HOMEPAGE=	http://search.cpan.org/~ikebe/Template-Stash-EscapeHTML/
COMMENT=	Escape HTML automatically in Template-Toolkit

DEPENDS+=	p5-Template-Toolkit-[0-9]*:../../www/p5-Template-Toolkit

PERL5_PACKLIST= auto/Template/Stash/EscapeHTML/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
