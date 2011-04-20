# $NetBSD: Makefile,v 1.7 2011/04/20 15:12:02 abs Exp $

DISTNAME=	ack-1.94
PKGREVISION=	2
PKGNAME=	p5-${DISTNAME}
CATEGORIES=	textproc perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=App/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/ack/
COMMENT=	Grep-like text finder
LICENSE=	${PERL5_LICENSE}

PKG_DESTDIR_SUPPORT=	user-destdir

USE_LANGUAGES=		# empty
PERL5_PACKLIST=		auto/ack/.packlist

DEPENDS+=	p5-File-Next>=0.4:../../devel/p5-File-Next
DEPENDS+=	p5-Term-ANSIColor-[0-9]*:../../devel/p5-Term-ANSIColor
BUILD_DEPENDS+=	{perl>=5.8.8,p5-Test-Harness>=2.5}:../../devel/p5-Test-Harness

SUBST_CLASSES+=		perl
SUBST_STAGE.perl=	do-configure
SUBST_FILES.perl=	ack
SUBST_SED.perl+=	-e "s,\#!/usr/bin/env perl,\#!${PERL5},"
SUBST_MESSAGE.files=	Rewriting /usr/bin/env perl.

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
