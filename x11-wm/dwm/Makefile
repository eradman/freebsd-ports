PORTNAME=	dwm
DISTVERSION=	6.8
PORTREVISION=	2
CATEGORIES=	x11-wm
MASTER_SITES=	http://dl.suckless.org/${PORTNAME}/

MAINTAINER=	ericshane@eradman.com
COMMENT=	Dynamic, small, fast and simple window manager
WWW=		https://dwm.suckless.org/

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

LIB_DEPENDS=	libfontconfig.so:x11-fonts/fontconfig

USES=		xorg
USE_XORG=	x11 xft

MAKE_ARGS=	CC="${CC}" \
		FREETYPEINC="${LOCALBASE}/include/freetype2" \
		PREFIX="${PREFIX}" \
		VERSION="${PORTVERSION}" \
		X11INC="${LOCALBASE}/include" \
		X11LIB="${LOCALBASE}/lib"

SUB_FILES=	dwm.desktop
SUB_LIST=	COMMENT="${COMMENT}"
PLIST_FILES=	bin/dwm \
		share/man/man1/dwm.1.gz \
		share/xsessions/dwm.desktop
PORTDOCS=	README

OPTIONS_DEFINE=		DOCS XINERAMA
OPTIONS_DEFAULT=	XINERAMA

RUN_DEPENDS=	dmenu:x11/dmenu st:x11/sterm

EXTRA_PATCHES=	${PATCHDIR}/volumecontrol-patch-config.def.h

XINERAMA_USE=		XORG=xinerama
XINERAMA_MAKE_ARGS_OFF=	XINERAMAFLAGS= \
			XINERAMALIBS=

post-configure:
	@${REINPLACE_CMD} -E \
		-e "s|(CFLAGS[[:space:]]*)= |\1+= |" \
		-e "s|(CPPFLAGS[[:space:]]*)= |\1+= |" \
		-e "s|(LDFLAGS[[:space:]]*)= |\1+= |" \
		${WRKSRC}/config.mk

post-install:
	@${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/dwm
	@${MKDIR} ${STAGEDIR}${PREFIX}/share/xsessions
	${INSTALL_DATA} ${WRKDIR}/dwm.desktop ${STAGEDIR}${PREFIX}/share/xsessions

post-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README ${STAGEDIR}${DOCSDIR}

do-test:
	/usr/libexec/atf-check -s exit:1 -e match:"dwm-${PORTVERSION}" \
		${STAGEDIR}${PREFIX}/bin/dwm -v

.include <bsd.port.mk>
