# $NetBSD: Makefile,v 1.16 2019/08/11 13:25:01 wiz Exp $

DISTNAME=	Template-Stash-HTML-Entities-1.3.1
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	11
CATEGORIES=	www perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=../../authors/id/Y/YO/YOSHIDA/}

MAINTAINER=	abs@absd.org
HOMEPAGE=	https://metacpan.org/release/Template-Stash-HTML-Entities
COMMENT=	Encode Template toolkit stash values using HTML::Entities

DEPENDS+=	p5-HTML-Parser-[0-9]*:../../www/p5-HTML-Parser
DEPENDS+=	p5-Template-Toolkit-[0-9]*:../../www/p5-Template-Toolkit

USE_LANGUAGES=	#

MAKE_ENV+=	PERL_USE_UNSAFE_INC=1
PERL5_PACKLIST=	auto/Template/Stash/HTML/Entities/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
