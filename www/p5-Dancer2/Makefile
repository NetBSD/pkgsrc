# $NetBSD: Makefile,v 1.51 2019/08/11 13:24:36 wiz Exp $

DISTNAME=	Dancer2-0.208000
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	1
CATEGORIES=	www perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=../../authors/id/C/CR/CROMEDOME/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://metacpan.org/release/Dancer2
COMMENT=	Lightweight yet powerful web application framework
LICENSE=	${PERL5_LICENSE}

USE_LANGUAGES=	# empty
PERL5_PACKLIST= auto/Dancer2/.packlist

BUILD_DEPENDS+=	p5-ExtUtils-MakeMaker>=7.12:../../devel/p5-ExtUtils-MakeMaker
BUILD_DEPENDS+=	p5-Test-Memory-Cycle>=0:../../devel/p5-Test-Memory-Cycle
BUILD_DEPENDS+=	p5-Test-MockTime>=0:../../time/p5-Test-MockTime
BUILD_DEPENDS+=	p5-Test-TCP>=0:../../net/p5-Test-TCP
BUILD_DEPENDS+=	p5-Test-Fatal>=0:../../devel/p5-Test-Fatal
BUILD_DEPENDS+=	p5-File-ShareDir-Install>=0.06:../../devel/p5-File-ShareDir-Install
BUILD_DEPENDS+=	p5-LWP-Protocol-PSGI>=0.06:../../www/p5-LWP-Protocol-PSGI

DEPENDS+=	p5-App-Cmd>=0:../../devel/p5-App-Cmd
DEPENDS+=	p5-Capture-Tiny>=0.12:../../devel/p5-Capture-Tiny
DEPENDS+=	p5-Crypt-URandom>=0:../../security/p5-Crypt-URandom
DEPENDS+=	p5-Config-Any>=0:../../devel/p5-Config-Any
#DEPENDS+=	{perl>=5.9.3,p5-Digest-SHA>=0}:../../security/p5-Digest-SHA
DEPENDS+=	p5-File-Share>=0:../../devel/p5-File-Share
DEPENDS+=	p5-Hash-Merge-Simple>=0:../../devel/p5-Hash-Merge-Simple
DEPENDS+=	p5-HTTP-Body>=0:../../www/p5-HTTP-Body
DEPENDS+=	p5-HTTP-Date>=0:../../www/p5-HTTP-Date
DEPENDS+=	p5-HTTP-Message>=0:../../www/p5-HTTP-Message
DEPENDS+=	p5-JSON>=0:../../converters/p5-JSON
DEPENDS+=	p5-JSON-MaybeXS>=0:../../converters/p5-JSON-MaybeXS
#DEPENDS+=	{perl>=5.7.3,p5-MIME-Base64>=0}:../../converters/p5-MIME-Base64
DEPENDS+=	p5-Module-Pluggable>=0:../../devel/p5-Module-Pluggable
DEPENDS+=	p5-Moo>=2.000000:../../devel/p5-Moo
DEPENDS+=	p5-MooX-Types-MooseLike>=0.16:../../devel/p5-MooX-Types-MooseLike
DEPENDS+=	p5-MooX-Types-MooseLike-Numeric>=0:../../devel/p5-MooX-Types-MooseLike-Numeric
DEPENDS+=	p5-Plack>=1.0035:../../www/p5-Plack
DEPENDS+=	p5-Plack-Middleware-FixMissingBodyInRedirect>=0:../../www/p5-Plack-Middleware-FixMissingBodyInRedirect
DEPENDS+=	p5-Plack-Middleware-RemoveRedundantBody>=0:../../www/p5-Plack-Middleware-RemoveRedundantBody
DEPENDS+=	p5-Return-MultiLevel>=0:../../devel/p5-Return-MultiLevel
DEPENDS+=	p5-Role-Tiny>=2.000000:../../devel/p5-Role-Tiny
DEPENDS+=	p5-Safe-Isa>=0:../../devel/p5-Safe-Isa
DEPENDS+=	p5-Template-Tiny>=0:../../textproc/p5-Template-Tiny
DEPENDS+=	p5-Template-Toolkit>=0:../../www/p5-Template-Toolkit
DEPENDS+=	p5-Type-Tiny>=1.000006:../../devel/p5-Type-Tiny
DEPENDS+=	p5-URI>=0:../../www/p5-URI
DEPENDS+=	p5-YAML>=0:../../textproc/p5-YAML
DEPENDS+=	p5-YAML-LibYAML>=0:../../textproc/p5-YAML-LibYAML
DEPENDS+=	p5-libwww>=0:../../www/p5-libwww

REPLACE_PERL+=	share/skel/bin/+app.psgi
REPLACE_PERL+=	script/dancer2

post-extract:
	${CHMOD} -x ${WRKSRC}/share/skel/public/+dispatch.cgi

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
